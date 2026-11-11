#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1005],k[505],a[505][1005],t[505][1005];
int x[1005],y[1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<= m;i++){
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>k[i];
		for(int j = 1; j<= k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i = 1;i<=q;i++){
		int ans=1000000005;
		cin>>x[i]>>y[i];
		for(int z=1;z<=n;z++){
			bool bx=false,by=false;
			int lstart,lover;
			for(int l=1;l<=k[z];l++){
				if(a[z][l]==x[i]){
					bx=true;
					lstart=l;
				}
				if(a[z][l]==y[i]){
					by==true;
					lover=l;
				}
			}
			if(bx&&by){
				ans=min(ans,w[x[i]]+w[y[i]]+t[z][lstart]+t[z][lover]);
			}
		}
		cout<<ans;
	}
	return 0;
}
