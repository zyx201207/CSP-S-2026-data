#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],minn[50005],tim[50005],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(d>=x[n]-x[1]){
			printf("0\n");
			continue;
		}
		if(c==11||c==12){
			long long p=d/(x[2]-x[1]);
			if(p<=1||p>=n){
				printf("0\n");
				continue;
			}
			printf("%lld\n",max(0ll,n-2*p+1));
			continue;
		}
		vector<long long> to[50005];
		queue<long long> q;
		ans=0;
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n&&x[j]-x[i]<=d;j++){
				to[i].push_back(j);
			}
		}
		for(long long i=1;i<=n;i++){
			memset(minn,0x3f3f3f3f,sizeof minn);
			memset(tim,0,sizeof tim);
			for(long long j=0;j<to[i].size();j++){
				minn[to[i][j]]=1;
				tim[to[i][j]]=1;
				q.push(to[i][j]);
			}
			while(!q.empty()){
				long long now=q.front();
				q.pop();
				for(long long j=0;j<to[now].size();j++){
					if(minn[to[now][j]]<minn[now]+1) continue;
					else if(minn[to[now][j]]==minn[now]+1){
						tim[to[now][j]]++;
					}else{
						minn[to[now][j]]=minn[now]+1;
						tim[to[now][j]]=1;
					}
					q.push(to[now][j]);
				}
			}
			for(long long j=i+1;j<=n;j++){
				if(tim[j]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}

