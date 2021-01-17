#include <string>
#include <iostream>
using namespace std;

// Utility function to find minimum of three numbers

int min(int x, int y) { return x > y ? y : x; }
int Min(int x, int y, int z) { return min(min(x, y), z); }

/*
What are the subproblems in this case ?
The idea is process all characters one by one staring from either from left or right sides of both strings.
Let us traverse from right corner, there are two possibilities for every pair of character being traversed.

m : Length of str1(first string)
n : Length of str2(second string)
If last characters of two strings are same, nothing much to do.Ignore last charactersand get count for remaining strings.So we recur for lengths m - 1 and n - 1.
Else(If last characters are not same), we consider all operations on ¡®str1¡¯, consider all three operations on last character of first string, recursively compute minimum cost for all three operationsand take minimum of three values.
Insert : Recur for mand n - 1
Remove : Recur for m - 1 and n
Replace : Recur for m - 1 and n - 1
Below is implementation of above Naive recursive solution.**/
// insert remove replace 
int editDist(string str1, string str2, int m, int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;

    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;

    cout << str1 << "," << str2 << "," << m << "," << n << endl;
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);

    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1
        + Min(editDist(str1, str2, m, n - 1), // Insert
            editDist(str1, str2, m - 1, n), // Remove
            editDist(str1, str2, m - 1,
                n - 1) // Replace
        );
}


int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int** dp = new int*[m+1];
    for (int i = 0; i < m+1; i++){
            dp[i] = new int[n+1];
    }

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j]
                = 1
                + Min(dp[i][j - 1], // Insert
                    dp[i - 1][j], // Remove
                    dp[i - 1][j - 1]); // Replace
        }
    }

    return dp[m][n];
}


// Driver code
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist(str1, str2, str1.length(),
        str2.length()) << endl;
    cout << editDistDP(str1, str2, str1.length(),
        str2.length());
    return 0;
}