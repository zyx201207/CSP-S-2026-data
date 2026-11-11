#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,int> PII;
const int N=5050;
int test,_,n;
ll d,x[N],ans,dist[N],num[N];
vector<int>v[N];
priority_queue<PII,vector<PII>,greater<PII> >q;
void dijkstra(int st){
	memset(dist,0x3f,sizeof dist);
	memset(num,0,sizeof num);
	dist[st]=0;
	q.push({0,st});
	num[st]=1;
	for(;!q.empty();){
		PII tt=q.top();q.pop();
		int t=tt.second;
		for(int i:v[t]){
			if(dist[i]>dist[t]+1){
				dist[i]=dist[t]+1;
				num[i]=num[t];
				q.push({dist[i],i});
			}else if(dist[i]==dist[t]+1){
				num[i]+=num[t];
			}
		}
	}
	return;
}
void solve1(){
	ans=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		v[i].clear();
		scanf("%lld",&x[i]);
		for(int j=i-1;j;j--){
			if(x[i]-x[j]>d)break;
			v[i].push_back(j);
			v[j].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=i+1;j<=n;j++){
			if(num[j]==2){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&test,&_);
	for(;_--;){
		solve1();
	}
	return 0;
}
