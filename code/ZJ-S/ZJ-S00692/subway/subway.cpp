#include<iostream>
#include<cstring>
using namespace std;
int c,n,m,d,q,f[1005][1005],w[500005],k,a[500005],t[500005],s,e;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++)f[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j1=1;j1<=k;j1++){
			for(int j2=1;j2<=k;j2++){
				f[a[j1]][a[j2]]=min(f[a[j1]][a[j2]],t[j1]+t[j2]);
			}
		}
	}
	for(int p=1;p<=m;p++){
		for(int i=1;i<=m;i++){
			if(i==p)continue;
			for(int j=1;j<=m;j++){
				if(i==j||j==p)continue;
				f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
			}
		}
	}
	for(;q--;){
		cin>>s>>e;
		cout<<w[s]+w[e]+f[s][e]<<'\n';
	}
	return 0;
}
