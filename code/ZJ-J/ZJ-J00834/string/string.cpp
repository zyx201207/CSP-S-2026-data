#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string s;
int dp[2005][2005];
int a[200005];
char c[200005];
void solve1(){
	s+=' ';
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int l=s.size()-1;
	for(int i=1;i<=l;i++){
		for(int j=i;j<=l;j++){
			dp[i][j]=1e9;
		}
	}
	for(int i=0;i<=l;i++) dp[i][i]=0;
	for(int len=2;len<=l;len++){
		for(int i=1;i+len-1<=l;i++){
			int j=i+len-1;
			if(s[i]==s[j]){
				if((i+1)<=(j-1))dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
				else{
					dp[i][j]=min(dp[i][j],dp[i+1][j]);	
					dp[i][j]=min(dp[i][j],dp[i][j-1]);
				}
			}
			else{
				dp[i][j]=min(dp[i][j],dp[i+1][j-1]+1);
			}
		}
	}
	cout<<dp[1][l];
}
void solve2(){
	s+=' ';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i];j++){
			s+=c[i];
		}
	}
	int l=s.size()-1;
	for(int i=1;i<=l;i++){
		for(int j=i;j<=l;j++){
			dp[i][j]=1e9;
		}
	}
	for(int i=0;i<=l;i++) dp[i][i]=0;
	for(int len=2;len<=l;len++){
		for(int i=1;i+len-1<=l;i++){
			int j=i+len-1;
			if(s[i]==s[j]){
				if((i+1)<=(j-1))dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
				else{
					dp[i][j]=min(dp[i][j],dp[i+1][j]);	
					dp[i][j]=min(dp[i][j],dp[i][j-1]);
				}
			}
			else{
				dp[i][j]=min(dp[i][j],dp[i+1][j-1]+1);
			}
		}
	}
	cout<<dp[1][l];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n<=10){
		solve1();
		return 0;
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mx=max(a[i],mx);
	}
	if(n<=2000&&mx==1){
		solve2();
		return 0;
	}
	return 0;
}
