#ifndef __MY_LINK__
#define __MY_LINK__

#include "FSElement.h"
#include "Dir.h"

/**
 * @brief Link class, subclass of the FSElement class
*/
class Link : public FSElement{
private:
    Dir* linker;

public:
    /**
     * @brief Link default constructor
    */
    Link(){}

    /**
     * @brief Link constructor, calls superclass constructor
     * @param n name of an element
     * @param l pointer to Dir object
    */
    Link( string n, Dir* l ) : FSElement( n, Type::Link ), linker( l ){}

    /**
     * @brief Link default destructor
    */
    ~Link(){}

    friend class Dir;

};

#endif