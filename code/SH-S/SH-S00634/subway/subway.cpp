#include<bits/stdc++.h>
using namespace std;
const int N=502,M=5e5+2,D=22;
int c,n,m,d,q,w[M],k,a,t,x,y;
map<int,int>b[M];
long long f[N][N],ans;
int main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++)
			cin>>a>>t,b[a][i]=t;
	}
	memset(f,0x3f,sizeof f);
	for(int i=0;i<n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto j:b[i]){
			int jf=j.first,js=j.second;
			for(auto k:b[i]){
				int kf=k.first,ks=k.second;
				f[jf][kf]=f[kf][jf]=min(f[jf][kf],(long long)js+ks);
			}
		}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int o=0;o<q;o++){
		cin>>x>>y;
		ans=1e18;
		for(auto i:b[x])
			for(auto j:b[y])
				ans=min(ans,i.second+f[i.first][j.first]+j.second);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
