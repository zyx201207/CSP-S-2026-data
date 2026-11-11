#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500008],a[10005][10005],t[10005][10005],k[505],x[500008],y[500008],f[10005]={1e9};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10001;j++){
			f[j]=1e9;
		}
		f[x[i]]=w[x[i]];
		for(int j=1;j<=k[j];j++){
			for(int l=1;l<=k[j];l++){
				long long v=1e9,v0;
				for(int l0=1;l0<=k[j];l0++){
					int l2=0;
					for(int l3=1;l3<=j;l3++)
						for(int l1=1;l1<=m;l1++){
							if(a[l3][l1]==l0)l2=1;
						}
					if(l2==1){
						v=min(v,f[l0]+t[j][l]);
						v0=l0;
					}
				}
				f[l]=min(f[l],v+t[j][l]+t[j][v0]);
			}
		}
		cout<<f[y[i]]+w[y[i]]<<endl;
	}
	return 0;
}


