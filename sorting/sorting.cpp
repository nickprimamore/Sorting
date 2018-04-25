/********************************************************************
 "I pledge my honor that I have abided by the Stevens Honor System."
  Nicholas Primamore and Matthew Monaco
 
  sorting.cpp
 *******************************************************************/

#include "sorting.hpp"
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

using namespace std;

/* Insertion sort
 *
 * Sort an array segment, in place:
 * Assume 0 <= l <= r and arr has length at least r.
 * Assume the elements of arr point to null-terminated strings.
 * Permute the elements, in place, to put them in non-decreasing order
 *
 * Use the insertion sort algorithm, with binary search to find the insertion point.
 */
int binarySearch(std::string arr[], string word, int left, int right){
    //base case: found insertion point b/c left and right are equal
    if(left <= right){
        if(strcmp(word, arr[low]) > 0){
            return left + 1;
        }
        else return low;
    }
    
    //word is at the midpoint
    int midpoint = (left+right)/2;
    if(strcmp(word, arr[midpoint]) == 0){
        return midpoint + 1;
    }
    
    //word is less than the midpoint
    if(strcmp(word, arr[midpoint]) < 0){
        return binarySearch(arr, word, left, midpoint - 1);
    }
    else{
        //word is greater than the midpoint
        return binarySearch(arr, word, midpoint + 1, right);
    }
}

void insertionsort(std::string arr[], int l, int r){
    for(int index = l; index < r; index++){
        int temp = index - 1; // we care about words to the left of current position
        string word = arr[index];
        int insertionPoint = binarySearch(arr, word, l, r);
        
        //shifting strings
        while(temp >= insertionPoint){
            arr[temp+1] = arr[temp];
            temp--;
        }
        
        //putting the current word in correct position
        arr[temp+1] = word;
    }
}

void quicksort(std::string arr[], int l, int r){
    if(l==r){
        return;
    }
    string partString = arr[l];
    
    int i = l;
    int j = r+1;
    
    do{
        do{
            i++;
        }while(arr[i].compare(partString) > 0);
        
        do{
            j--;
        }while(arr[j].compare(partString) <= 0);
        
        string temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }while(i>=j);
    
    string temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
    string temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    
    quicksort(arr, l, j);
    quicksort(arr, j, r);
}
void quicksortPlus(std::string arr[], int l, int r){
    if(r-l<=10){
        insertionsort(arr, l, r);
    }
    //pivot picking
    string low = arr[l];
    string mid = arr[(l+r)/2];
    string high = arr[r-1];
    string median;
    int medlocation;
    
    //low mid
    if(low.compare(mid)<=0){
        if(mid.compare(high)<=0){
            //low mid high
            medlocation = l+r;
        }else{
            if(low.compare(high)<=0){
                //low high mid
                medlocation = r-1;
            }else{
                //high low min
                medlocation = l;
            }
        }
    //mid low
    }else{
        if(low.compare(high)<=0){
            //mid low high
            medlocation = l;
        }else{
            if(mid.compare(high)<=0){
                //mid high low
                medlocation = r-1;
            }else{
                //high mid low
                medlocation = l+r;
            }
        }
    }
    
    median = arr[medlocation];
    string temp = arr[medlocation];
    arr[medlocation] = arr[l];
    arr[l] = temp;

    
    int i = l;
    int j = r+1;
    
    do{
        do{
            i++;
        }while(arr[i].compare(partString) > 0);
        
        do{
            j--;
        }while(arr[j].compare(partString) <= 0);
        
        string temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }while(i>=j);
    
    string temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
    string temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    
    quicksort(arr, l, j);
    quicksort(arr, j, r); 
}
