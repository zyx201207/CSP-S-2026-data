#include<bits/stdc++.h>
using namespace std;
string s,c,d;
long long b[10000001];
//long long dp[10000001][10000001];
int a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i]>>s[i];
		c+=b[i]*s[i];
	}
//	for(int i=1;i<=c.size();i++){
//		c[i]=1;
//	}
	for(int i=c.size()-1;i>=0;i--){
		d+=c[i];
	}
	if(c==d){
		cout<<0;
	}
	else{
		cout<<2;
	}
//	else{
//		for(int i=1;i<=c.size();i++){
//      		for(int j=1;j<=d.size();j++){
//				dp[i][j]=min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1;
//			}
//		}
//		cout<<dp[c.size()][d.size()];
//	}
	return 0;
} 
