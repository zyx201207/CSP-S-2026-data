#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500],a[500][500005],t[500][500005],s[500005],T;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			s[a[i][j]]++;		
			T=t[i][j];
		}
	}
	while(q--){
		long long ans; 
		cin>>x>>y;
		if(x==y)cout<<0;
		ans=ans+w[x]+w[y];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					long long mx=i,mn=j;
					while(a[mx][mn]!=y){
						ans+=t[mx][mn];
						for (int r=1;r<=n;r++){
							for (ar=1;ar<=k[i];ar++){
								if(a[mx][mn]==a[a][ar]&&a!=mx&&ar!=mn){
									mn=a,mx=ar;
								}
							}
						} 
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
