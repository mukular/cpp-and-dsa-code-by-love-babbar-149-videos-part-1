/*
Q.1. Given an array arr of integer numbers where arr[i] represents the number of pages in the ith book.
There are m numbers of students and the task is to allocate all the books to their students.
Allocate books in such a way that:
1. Each student gets atleast one book.
2. Each book should be allocated to a student.
3. Book allocation should be in a contiguous manner.
You have to allocate the book to m students such that the maximum number of pages assigned to a student is minimum.
*/
/*
Example: let m = 2, arr = {10,20,30,40}
three ways to allocate books:-
A. 10 and 20,30,40 max1 = max(10,90)
A. 10,20 and 30,40 max2 = max(30,70)
A. 10,20,30 and 40 max3 = max(60,40)

Answer = minimum of (max1,max2,max3) which is 60.
*/

/*
// Solution of question 1:-

bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;
    for(int i = 0; i < n; i++)
    {
        if(pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }

    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    int s = 0;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s <= e)
    {
        if(isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
*/

/*
Q.2. You are given an array 'arr' consisting of 'n' integers which denote the position of a 
stall.

You are also given an integer 'k' which denotes the number of aggressive cows.

You are given the task of assigning stalls to 'k' cows such that the minimum distance 
between any two of them is the maximum possible.

Print the maximum possible minimum distance.

Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at 
positions {1, 3}. Here distance between cows is 2.

Sample Input 1 :
6 4
0 3 4 7 10 9

Sample Output 1 :
3

Explanation to Sample Input 1 :
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed 
at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.

Sample Input 2 :
5 2
4 2 1 3 6

Sample Output 2 :
5

Expected time complexity:
Can you solve this in O(n * log(n)) time complexity?

Constraints :
2 <= 'n' <= 10 ^ 5
2 <= 'k' <= n
0 <= 'arr[i]' <= 10 ^ 9
Time Limit: 1 sec.

*/

/*
// Solution of question 2 :-

bool isPossible(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i = 0; i < stalls.size(); i++)
    {
        if(stalls[i]-lastPos >= mid)
        {
            cowCount++;
            if(cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int s = 0;
    int maxi = -1;
    for(int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }

    int e = maxi;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e)
    {
        if(isPossible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

*/