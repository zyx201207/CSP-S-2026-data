#include<bits/stdc++.h>
using namespace std;
int a[500005],dp[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[i]=a[i];
		for(int j=1;j<=n;j++){
			dp[j]=a[j];
			if(a[i]==a[j])
			dp[i]=a[j+1];
		}
	}
	int s;
	for(int i=1;i<=m;i++){
		s=0;
	for(int j=1;j<=n;j++)
	if(dp[j]==i){
		s++;
		cout<<s<<" ";
	}
	}
	
	return 0;
}
