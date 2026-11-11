#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e6+5,inf = 0x3f3f3f3f3f3f3f3f;
int a[N],n,d,cnt[N],dis[N];
void solve1(){
	int ans=0;
	queue<int>q;
	stack<int>s;
	for(int i=1;i<n;i++){
		q.push(i);
		for(int j=1;j<=n;j++)dis[j]=inf,cnt[j]=0;
		dis[i]=0;
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int j=u+1;a[j]-a[u]<=d;j++)if(cnt[j]<=2){
				s.push(j);
			}
			while(s.size()){
				int v=s.top();
				s.pop();
				if(dis[v]>=dis[u]+1){
					dis[v]=dis[u]+1;
					++cnt[v];
					if(cnt[v]<=3)q.push(v);
				}
			}
		}
		for(int j=i+1;j<=n;j++)if(cnt[j]==2){
			++ans;
		}
	}
	cout<<ans<<endl;
}
void solveA(){
	if(d<2*(a[2]-a[1])){
		cout<<0<<endl;
		return;
	}
	int k=d/(a[2]-a[1])*2-1;
	cout<<max(0ll,n-k)<<endl;
}
void solveB(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int p=upper_bound(a+1,a+n+1,a[i]+d)-a-2;
		if(a[n]>=a[p]+d)++ans;
	}
	cout<<ans<<endl;
}
void solve(){
	cin>>n>>d;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])f=0;
	}
	if(f)solveA();
	else if(n<=5000)solve1();
	else solveB();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 1
6 3
0 1 2 3 4 7
0
*/