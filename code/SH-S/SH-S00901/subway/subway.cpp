#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500010;
int c,n,m,d,q;
int w[MAXN];
int a[510][MAXN];//a[i][j] 第i条线路经过的第j个站点编号 
int t[510][MAXN];//t[i][j] i线路 a[i][j]站点编号 
int k[510];//k[i] 第i条线路经过的站点数 
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans+=w[x]+w[y];
		int flag=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					ans+=t[i][j];
				} 
				if(a[i][j]==y){
					ans+=t[i][j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
