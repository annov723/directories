#include "FSElement.h"

FSElement::~FSElement(){
    for( FSElement* e : down ) delete e;
}

void FSElement::operator+=( FSElement* e ){
    if( type != Type::Dir ) return;
    down.push_back( e );
    e->up = this;
}

void FSElement::add( FSElement* e ){
    if( type != Type::Dir ) return;
    down.push_back( e );
    e->up = this;
}

vector<FSElement*> FSElement::getFSElements( int depth, Type t ){
    vector<FSElement*> vec;
    if( type == t ) vec.push_back( this );
    collectElements( depth, t, vec );
    return vec;
}

vector<FSElement*> FSElement::getFSElements( string name ){
    vector<FSElement*> vec;
    searchPath( name, vec );
    return vec;
}

void FSElement::collectElements( int depth, Type t, vector<FSElement*>& vec ){
    if( depth == 0 ) return;

    for( FSElement* e : down ){
        if( e->getType() == t ) vec.push_back( e );
        if( e->getType() == Type::Dir ) e->collectElements( depth - 1, t, vec );
    }
}

void FSElement::searchPath( string name, vector<FSElement*>& vec ){
    for( auto e : down ){
        if( e->getName() == name ) vec.push_back( e );
        if( e->getType() == Type::Dir ) e->searchPath( name, vec );
    }
}

string FSElement::getPath(){
    FSElement* ptr = up;
    string s1 = name; 
    string s2;
    while( ptr != nullptr ){
        s2 = ptr->getName() + " " + s1;
        s1 = s2;
        ptr = ptr->getUp();
    }

    delete ptr;
    return s1;
}