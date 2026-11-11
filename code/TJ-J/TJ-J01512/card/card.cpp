#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000001];
int v[1000001];
int dp[1000001];
int s[1000001];
int ans[1000001];
int num[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		num[i]=1;
		if(s[a[i]]==0){
			s[a[i]]=i;
			dp[i]=i+1;
		}
		else{
			dp[i]=s[a[i]];
		}
	}
	for(int i=1;i<=n;i++){
		num[dp[i]]+=num[i];
	}
	for(int i=n;i>=1;i--){
		if(!v[a[i]]){
			ans[a[i]]=num[i];
			v[a[i]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
} 
