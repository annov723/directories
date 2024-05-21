#ifndef __MY_FILE__
#define __MY_FILE__

#include "FSElement.h"

/**
 * @brief File class, subclass of the FSElement class
*/
class File : public FSElement{
private:

public:
    /**
     * @brief File default constructor
    */
    File(){}

    /**
     * @brief File constructor, calls superclass constructor
     * @param n name of an element
    */
    File( string n ) : FSElement( n, Type::File ){}

    /**
     * @brief File default destructor
    */
    ~File(){}

    friend class Dir;

};

#endif