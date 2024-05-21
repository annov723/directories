#include "Dir.h"

Dir* Dir::findDir( string dirName ){
    if( name == dirName ) return this;

    for( FSElement* e : down ){
        if( e->getType() == Type::Dir ){
            if( e->getName() == dirName ) return static_cast<Dir*>( e );
            return static_cast<Dir*>( e )->findDir( dirName );
        }
    }
    return nullptr;
}

void Dir::printTree( ostream& os, int n ){
    for( FSElement* e : down ){
        os << string( n * 3, ' ' ) << e->getName();
        if( e->getType() == Type::File ) os << " (FILE)" << endl;
        else if( e->getType() == Type::Link ) os << " (LINK)" << endl;
        else{
            os << "(DIR)" << endl;
            static_cast<Dir*>( e )->printTree( os, n + 1 );
        }
    }
}

void Dir::listDirs( int depth ){
    vector<FSElement*> vec = getFSElements( depth, Type::Dir );
    for( FSElement* e : vec ) cout << e->getName() << " ";
    cout << endl;
}



ostream& operator<<( ostream& os, Dir& e ){
    os << e.getName();
    if( e.getType() == Type::File ) os << " (FILE)" << endl;
    else if( e.getType() == Type::Link ) os << " (LINK)" << endl;
    else e.printTree( os, 1 );
    return os;
}