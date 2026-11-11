#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300003]={0},dp[500005]={0},ans[500005]={0};
int qwe(int l,int r){
	int ls=0;
	for(int i=l;i<=r;i++){
		if(b[a[i]]!=i){
			ls+=qwe(i+1,b[a[i]]-1);
			i=b[a[i]];
			ans[a[i]]-=dp[i];
		}
		ls+=dp[i];
		ans[a[i]]+=ls;
	}
	return ls;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>0;i--){
		if(b[a[i]]==0){
			dp[i]=1;
			b[a[i]]=i;
		} else {
			dp[b[a[i]]]++;
		}
	}
	qwe(1,n);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
