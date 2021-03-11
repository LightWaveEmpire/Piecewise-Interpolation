#ifndef CORE_H_INCLUDE
#define CORE_H_INCLUDE

#include <vector>
#include <iostream>

using namespace std;

class Core 
{

private:
    std::vector<double> val; //< Data values
    std::vector<int> time; //< Store the time values for each val.

public:
    using const_iterator = std::vector<double>::const_iterator;
    using t_const_iterator = std::vector<int>::const_iterator;
    using iterator = std::vector<double>::iterator;

    /**
     * Construct a Core. 'val' defualt to 0.
     */ 
    Core();

    /**
     * Construct a Core.
     * 
     * @param src the Core to copy.     
     */  
    Core(const Core &src);

    /**
     * Core Deconstructor
     */ 
    ~Core();

    /**
     * Adds values to the vector 'val.'
     *
     * @param v The value to be added.
     */
    void addVal(double v);

    /**
     * Adds values to the vector 'time.'
     *
     * @param t The time to be added.
     */
    void addTime(int t);

    /**
     * Accessor to retrive the size of 'val.'
     *
     * @return val.size() The size of the vector, 'val.'
     */
    int getSize(){return val.size();}

    /**
     * Overloaded brackets operator to access 'val' values directly.
     * @param  i The location within the 'val' vector to access.
     * @return  int The value located at val[i].
     */
    double& operator[] (int i);

    /**
     * Overloaded brackets operator to read 'val' values directly.
     * @param  i The location within the 'val' vector to read.
     * @return  int The value located at val[i].
     */
    const double& operator[] (int i) const;

    /**
     * Takes the values from 'val' and 'time' and creates a line
     * that runs between each of the two points. It then outputs
     * this line to an output file.
     *
     * @param i The core being evaluated.
     */
    void interpolate(string filename, string i);

    /**
     * Takes the values from 'val' and 'time' and creates a line
     * that runs between all points. It then outputs
     * this line to an output file.
     *
     * @param i The core being evaluated.
     */
    void LinearInterp(string filename, string i);

    /**
     * Iterator to the beginning of the 'val' vector
     * 
     * @return const_iterator The const_iterator at the beginning
     * of the 'val' vector.
     */
    const_iterator begin() const;
    
    /**
     * Iterator to the end of the 'val' vector
     *
     * @return const_iterator The const_iterator at the end
     * of the 'val' vector.
     */
    const_iterator end() const;

    /**
     * Iterator to the beginning of the 'val' vector
     * 
     * @return iterator The iterator at the beginning
     * of the 'val' vector.
     */
    iterator begin();
    
    /**
     * Iterator to the end of the 'val' vector
     *
     * @return iterator The iterator at the end
     * of the 'val' vector.
     */
    iterator end();
    
    /**
     * Iterator to the beginning of the 'time' vector
     * 
     * @return const_iterator The const_iterator at the beginning
     * of the 'time' vector.
     */
    t_const_iterator tBegin() const;
    
    /**
     * Iterator to the end of the 'time' vector
     * 
     * @return const_iterator The const_iterator at the end of the
     * 'time' vector.
     */
    t_const_iterator tEnd() const;

    /**
     * Output a Core
     */
    void display(std::ostream& outs) const;
};

inline
std::ostream& operator<<(std::ostream& outs, const Core& prt)
{
    prt.display(outs);

    return outs;
}

#endif