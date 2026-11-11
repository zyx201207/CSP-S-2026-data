#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],c,n,m,d,q,t[10005],k,l,r,tl,tr;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=0x3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>l>>tl>>r>>tr;
		a[l][r]=tl+tr+t[l]+t[r];
		a[r][l]=tl+tr+t[l]+t[r];
	}
	for(int z=1;z<=m;z++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=min(a[i][j],a[i][z]+a[z][j]);
			}
		}
	}
	int o,p;
	for(int i=1;i<=q;i++){
		cin>>o>>p;
		cout<<a[o][p]<<endl;
	}
	return 0;
}
