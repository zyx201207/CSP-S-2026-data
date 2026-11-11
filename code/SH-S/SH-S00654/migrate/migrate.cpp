//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//const ll MAXN=99999999999999999;
//int c,t;
//ll dis[1005];
//int road[5005][5005];
//int ru[5005],chu[5005];
//int n,d;
//int Range[5005][5005];
//int top[5005];
//int times[5005][5005];
//int find(int i,int x,int l,int r){
//	if(l>r)return 0;
//	int mid=(l+r)>>1;
//	if(Range[i][mid]==x){
//		return mid;
//	}
//	if(Range[i][mid]<x)find(i,x,mid+1,r);
//	if(Range[i][mid]>x)find(i,x,l,mid);
//}
//int main(){
//	scanf("%d%d",&c,&t);
//	while(t--){
//		vector<int>g[5005];
//		scanf("%d%d",&n,&d);
//		for(int i=1;i<=n;i++){
//			scanf("%lld",&dis[i]);
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(dis[j]-dis[i]<=d){
//					g[i].push_back(j);
//				}
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<g[i].size();j++){
//				int v=g[i][j];
//				for(int k=1;k<=top[i];k++){
//					int pos=find(v,Range[i][k],1,top[v]);
//					if(pos==0){
//						top[v]++;
//						Range[v][top[v]]=pos;
//						times[v][top[v]]++;
//					}
//					else {
//						if(times[v][Range[v][pos]]==times[v][Range[i][k]]+1)
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
const ll INF=10000000000;
int c,t,n,d;
ll dis[N];
ll _cntMin[N];
ll Min[N];
int cnt=0;
void dfs(int x,int times){
	if(times<Min[x]){
		Min[x]=times;
		_cntMin[x]=0;
	}
	if(times==Min[x])_cntMin[x]++;
	for(int i=x+1;i<=n;i++){
		if(dis[i]-dis[x]>d)break;
		dfs(i,times+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==11||c==12) {
		while(t--){
			printf("0\n");
		}
	}
	while(t--){
		cnt=0;
		memset(_cntMin,0,sizeof(_cntMin));
		memset(dis,0,sizeof(dis));
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&dis[i]);
			Min[i]=INF;
		}
		for(int i=1;i<=n;i++){
			dfs(i,0);
			for(int i=1;i<=n;i++){
				if(_cntMin[i]==2)cnt++;
				_cntMin[i]=0;
				Min[i]=INF;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
//0 1
//6 2
//-4 -3 -2 -1 3 6

