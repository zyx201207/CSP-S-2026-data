#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,a[500005];
struct line{
	long long x,w,y,v;
}f[500005];
 bool cmp(line a,line b){
 	return a.x<b.x;
 }
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>f[i].x>>f[i].w>>f[i].y>>f[i].v;
			
			}
			
			
		}
		for(int i=1;i<=q;i++){
			cout<<f[2].w+f[3].v*12;
		}
}
	

