#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int nx[500005];
int dp[500005];
int ans[500005];
int add[500005];
int s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		nx[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(nx[i]==0){
			dp[i]=i+1;
			add[i]=a[i];
		}
		else{
			dp[i]=nx[i];
		}
	}
	for(int i=1;i<=n;i++){
		s[i]+=1;
	    s[dp[i]]+=s[i];
	}
	for(int i=n;i>=1;i--){
		ans[add[i]]+=s[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}