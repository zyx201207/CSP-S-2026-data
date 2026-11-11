#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N=1e4+5,M=1e4;
int t,c,n,d,ans,a[N],v[N],p[N];
void bfs(int x){
	queue<pair<int,int>>q;
	q.push(make_pair(x,0));
	while(!q.empty()){
		auto u=q.front();q.pop();
//		cout<<u.fi<<'\n';
		if(v[u.fi]){
			if(u.se==v[u.fi])p[u.fi]++;
			if(u.fi!=x&&u.se>v[u.fi])continue;
		}
		else v[u.fi]=u.se,p[u.fi]++;
		for(int j=1;j<=n;j++){
			if(abs(a[j]-a[u.fi])<=d&&j!=x&&j!=u.fi){
				q.push(make_pair(j,u.se+1));
//				if(n==5)cout<<u.fi<<"->"<<j<<' '<<u.se+1<<'\n';
			}
		}
	}
}
int init(){
	cin>>n>>d,ans=0;
//	cout<<n<<'\n';
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>=1e4)return cout<<"0\n",0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)v[j]=p[j]=0;
		v[i]=1e15,bfs(i);
		for(int j=1;j<=n;j++){
			if(p[j]==2)ans++;
//			if(n==5)cout<<p[j]<<' ';
		}
//		if(n==5)cout<<'\n';
	}
	cout<<ans/2<<'\n';
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
//	t=1;
	while(t--)init();
	return 0;
}
/*
hard!hard!
hot!hot!
mihuoxingweidashangshishenme?

0 4
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
16:23 pts=[24,40].
*/
