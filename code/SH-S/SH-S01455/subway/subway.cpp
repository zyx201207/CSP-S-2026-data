#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,p,d,q,sx,ex,ans;
const int MAXN=505;
vector<int> G[MAXN];
int a[MAXN],mv[MAXN][MAXN],w[MAXN],com;
struct node{
	int id,t;
}m[MAXN][MAXN];
bool flag[MAXN];
signed main(){
	memset(mv,0x3f,sizeof(mv));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>p>>d>>q;
	for(int i=1;i<=p;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=a[i];j++){
			cin>>m[j][i].id>>m[j][i].t;
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=a[l];i++){
			for(int j=1;j<=a[l];j++){
				if(i==j) continue;				
				if(mv[m[i][l].id][m[j][l].id]==4557430888798830399){
					G[m[i][l].id].push_back(m[j][l].id);
					G[m[j][l].id].push_back(m[i][l].id);				
				}
				mv[m[i][l].id][m[j][l].id]=min(mv[m[i][l].id][m[j][l].id],m[i][l].t+m[j][l].t);
				mv[m[j][l].id][m[i][l].id]=mv[m[i][l].id][m[j][l].id];
			}
		}
	}
//	for(int l=1;l<=p;l++){
		for(int i=1;i<=p;i++){
			for(int j=1;j<=p;j++){
				for(int k=1;k<=p;k++){
					mv[i][j]=min(mv[i][j],mv[i][k]+mv[k][j]);
					mv[j][i]=mv[i][j];
					if(mv[i][j]<4557430888798830399){
						G[i].push_back(i);
						G[j].push_back(i);				
					}
				}	
			}
		}		
//	}
	for(int i=1;i<=q;i++){
		memset(flag,0,sizeof(flag));
		ans=5e12;
		cin>>sx>>ex;
		flag[sx]=1;
		cout<<mv[sx][ex]+w[sx]+w[ex]<<endl;
	}
}

