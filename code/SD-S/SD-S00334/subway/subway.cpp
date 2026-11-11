#include<bits/stdc++.h>
using namespace std;
int w[500005];
struct train{
	int a[505],t[505],k;
}h[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>h[i].k;
		for(int j=1;j<=2*h[i].k;j++){
			cin>>h[i].a[j]>>h[i].t[j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int mina=500005,minb=500005;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2*h[i].k;j++){
				if(h[i].a[j]==x){
					mina=min(mina,h[i].t[j]);
				}
				if(h[i].a[j]==y){
					minb=min(minb,h[i].t[j]);
				}
			}
		}
		cout<<w[x]+w[y]+mina+minb<<"\n";
	}
	return 0;
}

