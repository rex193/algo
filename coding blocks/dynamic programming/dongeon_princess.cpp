
#include<iostream>
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
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
//naive Dp
int solve1(vector<vector<int>> &A){
  int row=A.size();
int col=A[0].size();
vector<vector<int>>dp(row,vector<int>(col));

if(A[row-1][col-1]<=0)
    dp[row-1][col-1]=1+abs(A[row-1][col-1]);

for(int j=col-2;j>=0;j--){
    dp[row-1][j]=max(0,dp[row-1][j+1]-A[row-1][j]);
    if(A[row-1][j]<=0){
        if(dp[row-1][j]==abs(A[row-1][j]))
            dp[row-1][j]++;
    }
}

for(int i=row-2;i>=0;i--){
    dp[i][col-1]=max(0,dp[i+1][col-1]-A[i][col-1]);
    if(A[i][col-1]<=0){
        if(dp[i][col-1]==abs(A[i][col-1]))
            dp[i][col-1]++;
    }

}
for(int i=row-2;i>=0;i--){
    for(int j=col-2;j>=0;j--){
        int l=max(0,dp[i+1][j]-A[i][j]);
        int r=max(0,dp[i][j+1]-A[i][j]);
        dp[i][j]=min(l,r);
        if(A[i][j]<=0){
            if(dp[i][j]==abs(A[i][j]))
                dp[i][j]++;
        }
    }
}
return max(dp[0][0],1);
}
int solve(vector<vector<int> > &dungeon){
	int M = dungeon.size();
    int N = dungeon[0].size();
    vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
    hp[M][N - 1] = 1;
    hp[M - 1][N] = 1;
    for (int i = M - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
            hp[i][j] = need <= 0 ? 1 : need;
        }
    }
    return hp[0][0];
}
int main(){
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   	int a,b;
   	cin>>a>>b;
   	vector<vector<int>> A(a,vector<int>(b,0));
   	for(int i=0;i<a;i++){
   		for(int j=0;j<b;j++){
   			int t=0;
   			cin>>t;
   			A[i][j] = t;
   		}
   	}
   	cout<<solve(A)<<endl;
	return 0;
}
