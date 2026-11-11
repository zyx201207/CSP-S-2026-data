#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
	int w;
	int k[505];
}mp[N];
int c,n,m,d,q;
vector<int> bl[N];
int bg(int x,int y){
	for(int i=0;i<bl[x].size();i++){
		for(int j=0;j<bl[y].size();j++){
			if(bl[x][i]==bl[y][j]) return bl[x][i];
		}
	}
	return -1;
}
int bo(int x,int y){
	for(int i=0;i<bl[x].size();i++){
		for(int j=0;j<bl[y].size();j++){
			for(int k=1;k<=m;k++){
				for(int z=0;z<bl[k].size();z++){
					if(bl[k][z]==bl[x][i]){
						for(int g=0;g<bl[k].size();g++){
							if(bl[k][g]==bl[y][j]){
								return k;
							}
						}
					}
				}
			}
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	const int nn=n+5,mm=m+5;
	int sd[nn][nn];
	memset(sd,0,sizeof(sd));
	for(int i=1;i<=m;i++){
		scanf("%d",&mp[i].w);
	}
	for(int i=1;i<=n;i++){
		int k1;
		scanf("%d",&k1);
		for(int j=1;j<=k1;j++){
			int a1,t1;
			scanf("%d%d",&a1,&t1);
			mp[a1].k[i]=t1;
			bl[a1].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			int bll=bg(i,j);
			if(bll==-1) continue;
			sd[i][j]=mp[i].w+mp[i].k[bll]+mp[j].w+mp[j].k[bll];
			sd[j][i]=sd[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(bg(i,j)!=-1) continue;
			int k2=bo(i,j);
			if(k2==-1) continue;
			sd[i][j]=sd[i][k2]+sd[k2][j]-2*mp[k2].w;
			sd[j][i]=sd[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int v=1;v<=m;v++){
				if(i==j||j==v||i==v) continue;
				if(sd[i][v]&&sd[v][j]&&sd[i][j]){
					if(sd[i][v]+sd[v][j]-2*mp[v].w<sd[i][j]){
						sd[i][j]=sd[i][v]+sd[v][j]-2*mp[v].w;
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		cout<<sd[x][y]<<endl;
	}
	return 0;
}
