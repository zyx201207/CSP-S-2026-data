#include<bits/stdc++.h>
using namespace std;
long long c,m,n,v,k[505],w[500005];
int d,q,a[505][500005],t[505][500005],x,y,ans;
int s;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]<=2){
			s=1;
		}
		for(int j=1;i<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(s=1){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=k[j];l++){
					if(l==2){
						ans+=t[j][l];
					}
				}
			}
			cout<<ans<<endl;
		}else{
			int T=t[1][1];
			cout<<T*m+w[1]<<endl;
		}
	}
	return 0;
}

