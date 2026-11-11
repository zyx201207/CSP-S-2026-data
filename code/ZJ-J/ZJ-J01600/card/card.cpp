#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=5e5+10,M=3e5+10;
int n,m,a[N],t[N],ans[M],v[M],flag=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=1;
	}
	if(!flag){
		for(int i=1;i<=n;++i){
			if(a[i]!=a[i+1]) v[a[i]]+=i;
		}
		for(int i=1;i<=m;++i){
			cout<<v[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		int nowi=0;
		for(int j=i;j<=n;++j){
			if(v[a[j]]>nowi) v[a[j]]=0;
			if(v[a[j]]<=nowi&&t[v[a[j]]]==a[j]){
				nowi=v[a[j]];
			}
			else{
				t[++nowi]=a[j];
				v[a[j]]=nowi;
			}
		}
		for(int j=1;j<=nowi;++j){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}
