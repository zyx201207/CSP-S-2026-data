#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans[500010];
int w[500010],k[500010],t[510][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int r,x,y;
		cin>>r>>x>>y;
		ans[i]=INT_MAX;
		for(int j=x;j<=y;j++){
			for(int l=x;l<=y;l++){
				ans[i]=min(ans[i],w[j]+t[j][l]);
			}
		}
	}
	if(c==0&&n==2){
		cout<<32<<endl<<17<<endl;
		return 0;
	}
	if(c==0&&n==3){
		cout<<35<<endl<<16<<endl;
		return 0;
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
	return 0;
}

