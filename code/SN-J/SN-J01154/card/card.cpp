#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],v[300005],w[300005],f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=1;
	}
	for(int i=n;i>=1;i--){
		if(!v[a[i]]){
			v[a[i]]=i;
		}
	}
	if(!f){
		for(int i=1;i<=m;i++){
			cout<<v[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			w[a[j]]++;
			j=v[a[j]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<w[i]<<' ';
	}
	return 0;
}
