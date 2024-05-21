#ifndef __MY_USER__
#define __MY_USER__

#include "Dir.h"

#include <future>

/**
 * @brief User class
*/
class User{
private:
    string name;
    FSElement* directory;

public:
    /**
     * @brief User default constructor
    */
    User(){}
    
    /**
     * @brief User constructor
     * @param n name of an element
     * @param d  pointer to a linked element
    */
    User( string n, Dir* d ) : name( n ), directory( d ){}

    FSElement* getDir() const{ return directory; }

};

/**
 * @brief asynchronously searches for an element by its name
 * @param u pointer to an user object
 * @param fileName name to search for
 */
vector<FSElement*> performAsyncUserSearch( User* u, string fileName );


/**
 * @brief search for a files
 * @param u pointer to an user object
 * @param fileName name to search for
 */
vector<FSElement*> searchFiles( User* u, string fileName );

#endif