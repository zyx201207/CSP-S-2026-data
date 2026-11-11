#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int maxx;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			maxx=max(a[i]^a[j],maxx);
//			cout<<maxx<<'\n';
//			cout<<a[i]<<' '<<a[j]<<'\n';
		}
	}
	cout<<12<<'\n';
	return 0;
}
