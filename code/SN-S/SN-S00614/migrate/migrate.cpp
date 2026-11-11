#include<iostream>
#include<string.h>
#include<queue>
#define  int  long long
using namespace std;
constexpr int N=2e6+5,INF=1e18;
bool Beg;
int C,n,d,a[N];
int lst[N];//f[N];

namespace Solve0{
int f[1005][1005];

int dfs(int L,int i){
	if(L==i||lst[L]==i)return 0;
	if(f[L][i])return f[L][i];
	f[L][i]=lst[i+1]-lst[i]+dfs(lst[L],lst[i]);
	return f[L][i];
}
void work(){
	memset(f,0,sizeof(f));
	int Ans=0;
	for(int i=1;i<=n;i++){
		if(lst[i]==i||lst[i]+1==i);
		else Ans+=dfs(i,lst[i]+1);
		cout<<Ans<<'\n';
	}
	cout<<Ans<<'\n';
	
	
}

}

namespace Solve1{
	int Ans;
	queue<int> q;
	int dis[N],ct[N];
	
	void BFS(int S){
		for(int i=1;i<=S;i++)
			dis[i]=INF,ct[i]=0;
		dis[S]=0,ct[S]=1,q.push(S);
		while(!q.empty()){
			int x=q.front(); q.pop();
			for(int i=lst[x];i<x;i++)
				if(dis[i]==INF){
					dis[i]=dis[x]+1,ct[i]=ct[x];
					q.push(i);
				}else if(dis[i]==dis[x]+1){
					if(ct[i]>2)break;
					ct[i]+=ct[x];
				}else break;
		}
		for(int i=1;i<=S;i++)
			Ans+=(ct[i]==2);
	}
	void work(){
		Ans=0;
		for(int i=1;i<=n;i++)BFS(i);
//			cout<<Ans<<' ';
//		cout<<'\n';
		cout<<Ans<<'\n';
	}
}

namespace Solve2{
	
	
	void work(){
		if(n==1){
			cout<<0<<'\n';
			return;
		}
		int e=a[2]-a[1];
		int c=d/e+1;
		if(c<=2)cout<<0<<'\n';
		else cout<<max(0ll,n-(2*c-3))<<'\n';
	}
}

void Solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,L=1;i<=n;i++){
		while(a[i]-a[L]>d)L++;
		lst[i]=L;
	}
	if(C<=10)Solve1::work();
	else if(C<=12)Solve2::work();
	else Solve0::work();
	
}
bool End;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T; cin>>C>>T;
	while(T--)Solve();
	cerr<<(&Beg-&End)/1024.0/1024.0<<" MB\n";
	return 0;
}
