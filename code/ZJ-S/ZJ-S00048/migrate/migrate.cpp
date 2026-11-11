#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const long long INF=0x3f3f3f3f3f3f3f3f;
int c,t;
int n;
long long d,x[N],ans;
long long st[N],num[N];
struct point{
	int id;
	long long step,number;
	bool operator<(const point&p)const{
		return step>p.step;
	}
};
priority_queue<point>q;
void bfs(int s){
	for(int i=1;i<=n;i++)st[i]=INF,num[i]=0ll;
	st[s]=0ll,num[s]=1ll,q.push((point){s,0ll,1ll});
	while(!q.empty()){
		point t=q.top();
		q.pop();
		if(t.step>st[t.id])continue;
		for(int i=t.id+1;x[t.id]+d>=x[i]&&i<=n;i++){
			long long nowst=t.step+1ll;
			if(nowst>st[i])continue;
			if(nowst<st[i])st[i]=nowst,num[i]=t.number;
			else num[i]+=t.number;
			q.push((point){i,st[i],num[i]});
		}
	}
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		ans=0ll;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++)if(num[j]==2ll)ans++;
		}printf("%lld\n",ans);
	}return 0;
}