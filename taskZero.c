#include "shell.h"

/**
 * SumSqaure- add the sum of the square of three numbers together.
 * @firstNum : the first Parameter.
 * @secondNum : the second parameter.
 * @thirdNum : the third parameter. 
 * @numberSum : the summation of the sqaure of the numbers
 * 
 * Return : the @numberSum  
 */


int SumSqaure(int firstNum,int secondNum,int thirdNum){
    int numberSum = (firstNum * 2) +(secondNum * 2) + (thirdNum);

    return numberSum;

}
