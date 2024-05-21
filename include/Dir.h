#ifndef __MY_DIR__
#define __MY_DIR__

#include "FSElement.h"
#include "File.h"

/**
 * @brief Dir class, subclass of the FSElement class, friend class of a File class
*/
class Dir : public FSElement{
private:

public:
    /**
     * @brief Dir default constructor
    */
    Dir(){}

    /**
     * @brief Dir constructor, calls superclass constructor
     * @param n name
    */
    Dir( string n ) : FSElement( n, Type::Dir ){}

    /**
     * @brief Dir default destructor
    */
    ~Dir(){}

    /**
     * @brief returns a pointer to a found directory from a directories tree
     * @param dirName name of a directory
    */
    Dir* findDir( string dirName );

    /**
     * @brief recursively goes through all the subdirectories of a directory and prints them
     * @param os standard output
     * @param n aligment counter
    */
    void printTree( ostream& os, int n );

    /**
     * @brief output all directories to a specified depth
     * @param depth how deep directories should be searched
    */
    void listDirs( int depth );
    
    /**
     * @brief standard output operator overloading, friend function of Dir class
     * @param os standard output
     * @param e Dir object
    */
    friend ostream& operator<<( ostream& os, Dir& e );

};

#endif