#include <bits/stdc++.h>
using namespace std;
int dp[20*510][20*510];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum;
	string s;
	cin>>n;
	for(int i=1,a;i<=n;i++){
		char c;
		cin>>a>>c;
		sum+=a;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	string s1,s2;
	for(int i=0;i<sum/2;i++){
		s1+=s[i];
	}
	for(int i=s.size()-1;i>=(sum+1)/2;i--){
		s2+=s[i];
	}
	for(int i=0;i<=s1.size();i++){
		for(int j=0;j<=s2.size();j++){
			if(i==0||j==0){
				dp[i][j]=max(i,j);
			}
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
		}
	}
	cout<<dp[s1.size()][s2.size()];
	return 0;
}