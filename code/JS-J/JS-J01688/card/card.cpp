#include<bits/stdc++.h>
using namespace std;
int a[500001],ans[300001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int nn[300001]={},f[300001]={};
		for(int j=i;j<=n;j++){
			if(nn[a[j]]){
				for(int k=f[a[j]];k<=j;k++){
					nn[a[k]]=0;
					f[a[k]]=0;
				}
			}
			nn[a[j]]=1;
			f[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=nn[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
