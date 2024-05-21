#include "User.h"

vector<FSElement*> performAsyncUserSearch( User* u, string fileName ){
    future<vector<FSElement*>> result = async( std::launch::async, searchFiles, u, fileName );
    return result.get();
}

vector<FSElement*> searchFiles( User* u, string fileName ){
    vector<FSElement*> vec = u->getDir()->getUp()->getUp()->getFSElements( fileName );
    return vec;
}