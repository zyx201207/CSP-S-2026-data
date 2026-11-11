#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <vector<long long>> dp;
struct Node{
	long long a;
}s[200005];
bool cmp(Node b,Node c){
	return b.a>c.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	dp.assign(m+1,vector<long long>(n+1,0));
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
	}
	sort(s+1,s+1+n,cmp);
	if(m==1) cout<<s[1].a;
	else{
		dp[1][1]=s[1].a;
		for(int i=1;i<=m;i++) dp[m][1]=s[1].a;
		for(int i=1;i<=n;i++) dp[1][n]=s[1].a;
		for(int i=2;i<=m;i++){
			for(int j=2;j<=n;j++){
				if(i==j) dp[i][j]=(dp[i-1][j-1]&s[i].a);
				else dp[i][j]=max(dp[i][j-1],(dp[i][j-2]&s[i].a));
			}
		}
		cout<<dp[m][n];
	}

	return 0;
}
//-O2 -std=c++14 -static
//Trick||Treat!
