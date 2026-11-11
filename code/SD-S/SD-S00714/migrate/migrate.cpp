#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d;
long long x[N];
pair<pair<int,int>,int> cnt[N];
pair<int,pair<int,int> > dist[N];
pair<int,int> dfs(int i,int j){
	if(dist[j].first==i)return dist[j].second;
	if(i==j)return {0,1};
	int res1=n,res2=0;
	for(int k=j-1;x[j]-x[k]<=d&&k>=i;k--){
		pair<int,int> t=dfs(i,k);
		if(res1>t.first+1){
			res2=t.second;
			res1=t.first+1;
		}
		else if(res1==t.first+1)res2+=t.second;
	}
	dist[j]={i,{res1,res2}};
	return {res1,res2};
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",x+i);
		}
		if(c<=10){
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(dfs(i,j).second==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
		else if(c<=12){
			int s=d/(x[2]-x[1]);
			if(s<=1)printf("0\n");
			else printf("%d\n",max(n-s*2+1,0));
		}
	}	
	return 0; 
}
