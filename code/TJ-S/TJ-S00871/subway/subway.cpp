#include<bits/stdc++.h>
#define int long long
using namespace std;
struct station{
	int k;
	int a[2005];
}st[505];
int t[505][2005];
int gra[2005][2005];
int gra1[2005][2005];
int c,n,m,d,q,minn=0x7fffffff,x,y;
bool vis[2003];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>gra[i][i],gra1[i][i]=gra[i][i];
	for(int i=1;i<=n;i++){
		cin>>st[i].k;
		for(int j=1;j<=st[i].k;j++) cin>>st[i].a[j],cin>>t[i][st[i].a[j]];
	}
	if(c<=11){
		for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) if(i!=j) gra[i][j]=gra1[i][j]=0x7fffffff;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=st[i].k;j++){
				for(int t1=j+1;t1<=st[i].k;t1++){
					gra[st[i].a[j]][st[i].a[t1]]=gra[st[i].a[t1]][st[i].a[j]]=min(gra[st[i].a[j]][st[i].a[t1]],t[i][st[i].a[j]]+t[i][st[i].a[t1]]);
				}
			}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int z=1;z<=m;z++){
					if(i!=j&&j!=z&&i!=z) gra[i][z]=min(gra[i][j]+gra[j][z],gra[i][z]);
				}
			}
		}					
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=m;j++) cout<<gra[i][j]<<" ";
//			cout<<endl;
//		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<gra[x][x]+gra[y][y]+gra[x][y]<<endl;
		}
	}
	return 0;
}
