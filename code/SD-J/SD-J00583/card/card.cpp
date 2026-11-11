#include<bits/stdc++.h>
using namespace std;
int a[500005],maxn[500005],c[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=1;
		}
		maxn[a[i]]=max(maxn[a[i]],i);
	}
	
	for(int i=1;i<=n;i++){
		c[i]=maxn[a[i]];
	}
	if(!f){
		for(int i=n;i>=1;i--){
			if(i==c[i]){
				ans[a[i]]+=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			ans[a[j]]++;
			j=c[j]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
