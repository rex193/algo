#include<iostream>
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define mod 10000000007
#define pb push_back	`

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef long long ll;


int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
int longest_palindrome(string A,int i,int j,vector<vector<int>> dp){
	if(i>j)
		return 0;
	if(i==j)
		return 1;
	if(dp[i][j]>0){
		return dp[i][j];
	}
	if(A[i] == A[j]){
		dp[i][j] = longest_palindrome(A,i+1,j-1,dp)+2;
		return dp[i][j];
	}
	else{
		dp[i][j] = MAX(longest_palindrome(A,i+1,j,dp),longest_palindrome(A,i,j-1,dp));
		return dp[i][j];
	}
}
int longest_palindromeDP(string A){
	int dp[A.length()][A.length()];
	for(int i=0; i < A.length(); i++){
            dp[i][i] = 1;
        }
	  for(int l = 2; l <= A.length(); l++){
            for(int i = 0; i < A.length()-l + 1; i++){
                int j = i + l - 1;
                if(l == 2 && A[i] == A[j]){
                    dp[i][j] = 2;
                }else if(A[i] == A[j]){
                    dp[i][j] = dp[i + 1][j-1] + 2;
                }else{
                    dp[i][j] = MAX(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][A.length()-1];
      }
      int main(){
       	// freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
         	string A;
          cin>>A;s
         	cout<<longest_palindromeDP(A)<<endl;
      	return 0;
      }
