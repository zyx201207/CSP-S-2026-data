#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M];
long long dis[N][N];
vector<int> t[N],a[N];
vector<pair<int,int>> line[M];
long long f(int x,int y){
	long long num=0x3f3f3f3f3f3f3f3f;
	for(int i=0,flag;i<(int)a[x].size();i++){
		flag=0;
		for(pair<int,int> j:line[a[x][i]]){
			if(j.first==y){
				flag=j.second;
				break;
			}
		}
		if(flag>0){
			num=min(num,0ll+t[x][i]+t[y][flag-1]);
		}
	}
	return num;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,x,y;j<=k;j++){
			scanf("%d %d",&x,&y);
			t[i].push_back(y);
			a[i].push_back(x);
			line[x].emplace_back(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i].size()>a[j].size()){
				dis[i][j]=dis[j][i]=f(j,i);
			}
			else{
				dis[i][j]=dis[j][i]=f(i,j);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	long long minn;
	for(int i=1,x,y;i<=q;i++){
		minn=0x3f3f3f3f3f3f3f3f;
		scanf("%d %d",&x,&y);
		for(pair<int,int> u:line[x]){
			for(pair<int,int> v:line[y]){
				minn=min(minn,dis[u.first][v.first]+t[u.first][u.second-1]+t[v.first][v.second-1]);
			}
		}
		printf("%lld\n",minn+w[x]+w[y]);
	}
	return 0;
}
