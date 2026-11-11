#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long T;
long long n;
long long d;
long long x[N];
long long Ans;
long long c;
long long dis[N],cnt[N];
long long bfs(long long s){
	queue<pair<long long,long long> > q;
	q.push({s,0});
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	cnt[s]=1;
	dis[s]=0;
	while(q.size()){
		long long tmp=q.front().first,len=q.front().second;q.pop();
		for(long long i=tmp+1;i<=n;i++){
			if(abs(x[i]-x[tmp])<=d){
				if(dis[tmp]+1<dis[i]){
					q.push({i,len+1});
					dis[i]=dis[tmp]+1;
					cnt[i]+=cnt[tmp];
				}else if(dis[tmp]+1==dis[i]){
					cnt[i]+=cnt[tmp];
				}
			}
		}
	}
	for(int i=s+1;i<=n;i++){
		Ans+=(cnt[i]==2);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		Ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>x[i];
		for(long long i=1;i<=n;i++){
			bfs(i);
		}
		cout<<Ans<<"\n";
	}
	return 0;
}

