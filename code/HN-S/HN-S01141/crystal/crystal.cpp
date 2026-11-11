#include<bits/stdc++.h>
#define ll long long
const int N = 5e5+10;
using namespace std;
template<class T>
inline void read(T &sum){
	int c = sum = 0;bool y = 1;
	while(c!='-'&&(c<'0'||c>'9'))if(c==EOF)return;else c=getchar();
	if(c=='-')y=0,c=getchar();
	while(c>='0'&&c<='9')sum=(sum<<1)+(sum<<3)+c-'0',c=getchar();
	sum=y?sum:-sum;
}
int n;
ll m,a[N],dp[N][2],ded=-1e12;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i = 1; i <= n; i++) read(a[i]);
	sort(a+1,a+n+1);
	dp[1][1]=0,dp[1][0]=0;
	for(int i = 2; i <= n; i++){
		dp[i][1] = dp[i-1][1]+1;
		dp[i][0] = dp[i-1][0]+dp[i][1]*(a[i]-a[i-1]);
		while(dp[i][0]>m){
			dp[i][1]--,
			dp[i][0] -= a[i]-a[i-dp[i][1]-1];
		}
	}
	for(int i = 1; i <= n; i++)ded=max(dp[i][1],ded);
	cout << ded+1;
	return 0;
}
