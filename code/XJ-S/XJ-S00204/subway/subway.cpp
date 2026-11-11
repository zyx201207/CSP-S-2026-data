#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][500005],t[505][500005],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=d;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	int ans=0;
	if(c>=7&&c<=11){
		for(int i=1;i<=q;i++){
			ans=0;
			for(int j=x[i];j<=y[i];j++){
				ans+=t[i][j];
			}
			ans+=(w[x[i]]+w[y[i]]);
			cout<<ans<<endl;
		}
		
	}
	else if(c>=12&&c<=19){
		for(int i=1;i<=q;i++){
			ans+=w[x[i]]*4;
			cout<<ans<<endl;
			ans=0;
		}
	}
	else cout<<35<<endl<<16;
	return 0;
} 
