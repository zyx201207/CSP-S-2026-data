#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],ww[300005],yr[300005],w;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ww[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		w=ww[a[i]];
		while(w<=n){
			yr[a[w]]++;
			w++;
			if(w>n)break;
			w=ww[a[w]];
		}
	}
	for(int i=1;i<=m;++i){
		cout<<yr[i]<<" ";
	}
	return 0;
}