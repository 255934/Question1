/**
 * @file complex_calculator.c
 * @author your name (you@domain.com)
 * @brief Source code for complex calculator
 * @version 0.1
 * @date 2021-03-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include "complex_calculator.h"

/**
 * @brief Complex sum function
 * 
 * @param cnum1 
 * @param cnum2 
 * @param csum 
 * @return error_t 
 */
error_t complex_sum(complex_t* cnum1, complex_t* cnum2, complex_t* csum)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    
    
    csum->real = cnum1->real + cnum2->real;
    csum->imaginary = cnum1->imaginary + cnum2->imaginary;

    return SUCCESS;

}
/**
 * @brief complex difference function
 * 
 * @param cnum1 
 * @param cnum2 
 * @param cdiff 
 * @return error_t 
 */
error_t complex_diff(complex_t* cnum1, complex_t* cnum2, complex_t* cdiff)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    
    
    cdiff->real = cnum1->real - cnum2->real;
    cdiff->imaginary = cnum1->imaginary - cnum2->imaginary;

    return SUCCESS;

}

/**
 * @brief complex product function
 * 
 * @param cnum1 
 * @param cnum2 
 * @param cprod 
 * @return error_t 
 */
error_t complex_prod(complex_t* cnum1, complex_t* cnum2, complex_t* cprod)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    
    
    cprod->real = (cnum1->real*cnum2->real) - (cnum1->imaginary*cnum2->imaginary);
    cprod->imaginary = (cnum1->imaginary*cnum2->real)+(cnum1->real*cnum2->imaginary);

    return SUCCESS;

}

/**
 * @brief  complex division function
 * 
 * @param cnum1 
 * @param cnum2 
 * @param cdiv 
 * @return error_t 
 */
error_t complex_div(complex_t* cnum1, complex_t* cnum2, complex_t* cdiv)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;

    /**
     * @brief Construct a new if object to check if the real and imaginary part of second complex number is equal to 0
     * 
     * @param real 
     */
    if((cnum2->real==0) && (cnum2->real==0)){
        cdiv->real = 0;
        cdiv->imaginary = 0;
    }
    /**
     * @brief if the real and imaginary part of second complex number are not equal to zero, we check the denominator of rationalization is equal to zero.
     * 
     */
    else if(((cnum2->real)*(cnum2->real) + (cnum2->imaginary)*(cnum2->imaginary))== 0){
        cdiv->real = 0;
        cdiv->imaginary = 0;
    }
    else{
    cdiv->real = ((cnum1->real*cnum2->real) + (cnum1->imaginary*cnum2->imaginary))/((cnum2->real)*(cnum2->real) + (cnum2->imaginary)*(cnum2->imaginary));
    cdiv->imaginary = ((cnum1->real*(-cnum2->imaginary)) + (cnum1->imaginary*cnum2->imaginary))/((cnum2->real)*(cnum2->real) + (cnum2->imaginary)*(cnum2->imaginary));
    }
    return SUCCESS;

}