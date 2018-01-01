/*Given two words A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example : 
edit distance between
"Anshuman" and "Antihuman" is 2.

Operation 1: Replace s with t.
Operation 2: Insert i.
*/

int Solution::minDistance(string s1, string s2) {
      int m = s1.length();
	int n = s2.length();
	int** dp = new int*[m + 1];
	for (int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
	}
	for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
           
            if (i==0)
                dp[i][j] = j; 
 
            
            else if (j==0)
                dp[i][j] = i; 
 
          
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
         
            else
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1])); 
        }
    }

	int ans =  dp[m][n];
	// delete 2d array
	for (int i =0; i <=  m; i++) {
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}
