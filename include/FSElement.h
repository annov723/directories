#ifndef __MY_FS__
#define __MY_FS__

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief enum class Type holding possible FSElement types
*/
enum class Type{
    File,
    Dir,
    Link
};

/**
 * @brief FSElement class representing a files system element
*/
class FSElement{
protected:
    string name;
    Type type;
    FSElement* up = nullptr;
    vector<FSElement*> down;

public:
    /**
     * @brief FSElement default constructor
    */
    FSElement(){}

    /**
     * @brief fSElement constructor
     * @param n name of an element
     * @param t type of an element
    */
    FSElement( string n, Type t ) : name( n ), type( t ){}

    /**
     * @brief fSElement default destructor
    */
    virtual ~FSElement();

    /**
     * @brief adds a new element to a dirs tree
     * @param e pointer to a FSElement object
    */
    void operator+=( FSElement* e );

    /**
     * @brief adds a new element to a dirs tree
     * @param e pointer to a FSElement object
    */
    void add( FSElement* e );

    /**
     * @brief returns vector of elements contained
    */
    vector<FSElement*> getDown() const{ return down; }

    /**
     * @brief returns pointer to an element above
    */
    FSElement* getUp() const{ return up; }

    /**
     * @brief returns name
    */
    string getName() const{ return name; }

    /**
     * @brief returns type
    */
    Type getType() const{ return type; }

    /**
     * @brief returns a vector of subelements of an object that match the pattern
     * @param depth search depth
     * @param t type of elements to search for
    */
    vector<FSElement*> getFSElements( int depth, Type t );

    /**
     * @brief returns FSeleemnt pointers vector
     * @param name of searching file
    */
    vector<FSElement*> getFSElements( string name );

    /**
     * @brief fSElement constructor
     * @param depth how deep to search for an element
     * @param t type of an element
     * @param vec vector ro save the pointers to found FSElement objects
    */
    void collectElements( int depth, Type t, vector<FSElement*>& vec );

    /**
     * @brief searches for a path to a file
     * @param name of element to be found
     * @param vec possible paths to this element
    */
    void searchPath( string name, vector<FSElement*>& vec );

    /**
     * @brief returns path to a file
    */
    string getPath();

};

#endif