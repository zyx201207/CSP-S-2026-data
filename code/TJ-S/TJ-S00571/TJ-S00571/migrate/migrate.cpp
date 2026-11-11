#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
template<typename T> bool tense(T &a,const T &b){return b<a?a=b,true:false;}
template<typename T> bool relax(T &a,const T &b){return a<b?a=b,true:false;}

namespace Force{
	const int N = 310;
	const long long INF = 0x3f3f3f3f3f3f3f3fll;
	long long a[N];
	int next[N];
	int dist[N];
	int cnt[N];
	int n;
	long long d;
	
	void solve(){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		/*
		for(int i=1;i<=n;i++) next[i] = 0;
		for(int i=1,j=1;i<=n;i++){
			if(j>n&&a[n]-a[i]<=d) relax(next[i],n);
			for(;j<=n&&a[j]-a[i]<=d;j++) relax(next[i],j);
		}
		*/
		long long res = 0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) dist[j] = INF,cnt[j] = 0;
			dist[i] = 0,cnt[i] = 1;
			for(int j=i;j<=n;j++){
				for(int k=j+1;k<=n;k++) if(a[k]-a[j]<=d){
					if(dist[j]+1==dist[k]) cnt[k]+=cnt[j];
					if(tense(dist[k],dist[j]+1)) cnt[k] = cnt[j];
				}
			}
			for(int j=i+1;j<=n;j++) res+=cnt[j]==2;
		}
		printf("%lld\n",res);
	}
}

namespace Better{
	const int N = 310;
	const long long INF = 0x3f3f3f3f3f3f3f3fll;
	long long a[N];
	int next[N];
	int dist[N];
	int cnt[N];
	int n;
	long long d;
	
	void solve(){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		/*
		for(int i=1;i<=n;i++) next[i] = 0;
		for(int i=1,j=1;i<=n;i++){
			if(j>n&&a[n]-a[i]<=d) relax(next[i],n);
			for(;j<=n&&a[j]-a[i]<=d;j++) relax(next[i],j);
		}
		*/
		
		long long res = 0;
		for(int i=n;i>=1;i--){
			dist[i] = 0,cnt[i] = 1;
			/*
			for(int j=i;j<=n;j++){
				for(int k=j+1;k<=n;k++) if(a[k]-a[j]<=d){
					if(dist[j]+1==dist[k]) cnt[k]+=cnt[j];
					if(tense(dist[k],dist[j]+1)) cnt[k] = cnt[j];
				}
			}
			*/
			for(int j=i+1;j<=n;j++) dist[j] = INF;
			for(int j=i+1;j<=n;j++) if(a[j]-a[i]<=d){
				if(dist[i]+1==dist[j]) cnt[j]++;
				if(tense(dist[j],dist[i]+1)) cnt[j] = 1;
			}
			for(int j=i+1;j<=n;j++) res+=cnt[j]==2;
		}
		printf("%lld\n",res);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		Force::solve();
		//Better::solve();
	}
	return 0;
}


