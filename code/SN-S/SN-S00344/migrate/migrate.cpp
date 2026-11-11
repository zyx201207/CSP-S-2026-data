// __       ___________________________________
// \ \     / /____  ____|  _______ \_____  ____|
//  \ \   / /    | |    | |______| |    | |
//   \ \ / /     | |    |         /     | |
//   /  ^ \      | |    |  ______ \     | |
//  / /  \ \     | |    | |______| |    | |
// /_/    \_\    |_|    |_________|     |_|
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define lowbit(x) (x & -x)
#define INF 0x3f3f3f3f3f3f3f3fll
#define inf 0x3f3f3f3f
#define FINF 0xcfcfcfcfcfcfcfcfll
#define finf 0xcfcfcfcf
using namespace std;
const int maxn=2e6+5;
const int maxm=1e6;
const int mod=998244353;
int n,m,t,ooo;
int b[maxn];
int c[maxn];
int a[maxn];
queue<pair<int,int> >q;
int ans;
void bfs(int o){
	q.push({o,0});
	for(int i=o;i<=n;i++)c[i]=b[i]=0;
	b[o]=0;c[o]=1;
	while(!q.empty()){
		pair<int,int>p=q.front();q.pop();
		int u=p.first,d=p.second;
		int h=upper_bound(a+1,a+n+1,a[u]+m)-a-1;
		for(int i=h;i>=u;i--){
			if(a[i]-a[u]>m)break;
			if(b[i]){
				if(d+1<=b[i])c[i]++;
				else continue;
			}
			else {
				b[i]=d+1;c[i]=1;
			}
			q.push({i,d+1});
			
		}
	}
//	for(int i=1;i<=n;i++)cout<<c[i]<<" ";
//	cout<<endl;
	for(int i=o;i<=n;i++)if(c[i]==2)ans++;
}
signed main()
{
	//°§±ø±ØÊ¤
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate4.in","r",stdin);
//	freopen("jmcakioi.txt","w",stdout);
	cin>>ooo>>t;
if(ooo==11||ooo==12){
while(t--){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if((a[2]-a[1])*2>m){
		cout<<0<<endl;
		continue;
	}
	if(a[1]+m>=a[n]){
		cout<<0<<endl;
		continue;
	}
	int u=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[1]>m)break;
		u=i;
	}
//	cout<<u<<endl
	u--;;
//	int h=u+1;
	cout<<n-u*2+1<<endl;
}
	return 0;
}
while(t--){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)b[j]=0;
		bfs(i);
	}
	cout<<ans<<endl;
}
	
	return 0;
}

