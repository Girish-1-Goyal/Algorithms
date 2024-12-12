/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>
#include <ctime>

using namespace std;

template < class c > struct rge {
    c b, e;
};
template < class c > rge<c> range(c i, c j){
    return rge<c>{i, j};
}
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);

struct debug {
    ~debug() { cerr << endl; }
    template < class c > typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
        cerr << boolalpha << i;
        return * this;
    }
    template < class c > typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
        return * this << range(begin(i), end(i)); 
    }
    template < class c, class b > debug & operator << (pair < b, c > d) {
        return * this << "(" << d.first << ", " << d.second << ")";
    }
    template < class c > debug & operator <<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        return * this << "]";
    }
};  
#define imie(...) " [" << #__VA_ARGS__ " : " << (__VA_ARGS__) << "]"

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low; // starting index of left of the array
    int right = mid + 1;; // starting index of right of the array
    while(low <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    //if element on the left half are still left
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    // if element on the right half are still left;
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    // copy all the element of the temp array into the origional array;
    for(int i = low; i <= high; ++i){
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &arr, int low, int high){
    if(low >= high){
        return;
    }
    int mid = (low + high) / 2; // mid of the array
    merge_sort(arr, low, mid); //left half
    merge_sort(arr, mid + 1, high); //right half
    merge(arr, low, mid, high); //merging sorted half
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    for(int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << "\n";
    merge_sort(arr, 0, arr.size() - 1);
    for(int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

/*
Merge sort is basically a recursive sorting algorithm on the basis divide and merge

arr = [3, 2, 4, 5, 1, 9, 7, 6]
       0--------------------7
divide the array into 2 equal halves
set 0 as low and 7 as high

int mid = (low + high) / 2;   (0 + 7)/2 = 3
first half will be = [3, 2, 4, 5]
second half will be = [1, 9, 7, 6]

if we take the first half of the array then the array will be the => [3, 2, 4, 5] => low ------- mid
if we take the second half of the array then the array will be the => [1, 9, 7, 6] => mid + 1 ---------high


in the merge function we will check the element of the arrays that are divided =>

1. we will initialize an temp array to store tha sorted elements in from the array
2. mark left = low and right = mid + 1;

[-,-,-,-,-] [-,-,-,-,-,-]
 left        right

=> while(left <= mid && right <= high)

till when the array of left does not touch the mid and the right of the array does not touch the high
of the array and then check the arr of left and then the array of right if the arr of left is less then the array of right then the arr left
is push to the temp array and then increase the counter of left++ and else increase the counter of the right++

=> arr[left] <= arr[right] and then push the element in the temp;

if the element in the array are left to compare then it will transfer all the element in the temp array

if(left <= mid) push all the element in the temp array and then left++;
if(right <= high) push all the element in the temp array and then right++;

the last step to transfer all the temp array element into the original array;






*/
