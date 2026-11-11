#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
using namespace std;
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释
const int N=5e5+10,M=505,Q=2e4+10;
int c,n,m,d,q;
int w[N],k[N],bk[N];
int a[M][Q],t[M][Q];
int nn=999999999;
void dfs(int st,int ed,int zt,int tt){
	if(st==ed){
		nn=min(nn,tt+t[zt][ed]);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			if((t[i][st] != -1)&&(a[i][j] == st)){
				if(zt!=i)dfs(a[i][j+1],ed,i,tt+t[i][st]+t[zt][st]);
				else dfs(a[i][j+1],ed,i,tt+t[i][st]);
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(t,-1,sizeof t);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>y;
			a[i][j]=x;
			t[i][x]=y;
		}
	}
	if(c==7||c==8||c==9||c==10||c==11){
		while(q--){
			int x,y;cin>>x>>y;
			int ans=w[x]+w[y];
			int l=min(x,y),r=max(x,y);
			for(int i=l;i<r;i++){
				for(int j=l;j<=r;j++){
					if(t[i][j]>=0)ans+=t[i][j];
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)sort(a[i]+1,a[i]+k[i]+1);
	while(q--){
		nn=999999999;
		int xx,yy;cin>>xx>>yy;
		int ans=w[xx]+w[yy];
		int p;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==min(xx,yy))p=i;
			}
		}
		dfs(min(xx,yy),max(xx,yy),p,0);
		ans+=nn;
		cout<<ans<<endl;
	}
	return 0;
}
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释

