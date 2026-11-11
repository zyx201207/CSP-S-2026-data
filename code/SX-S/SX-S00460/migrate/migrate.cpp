#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
const int N=5e5+5;
int n,d,a[N],f[N],fw,t,g[N];
void act(){
	cin>>n>>d;
	int ans=0;
	for (int i=1;i<=n;i++)cin>>a[i];
	a[n+1]=9e18;
	for (int i=1;i<=n;i++){
		f[i]=1;
		deque<int> q;
		q.push_back(i);
		int sum=1,id=i,lst=i+1;
		g[i]=0;
		for (int j=i+1;j<=n;j++){
			g[j]=g[j-1];
			if (a[j]-a[id]>d)g[j]++,id=j-1;
			while (!q.empty()&&(a[j]-a[q.front()]>d||g[q.front()]+1<g[j]))sum-=f[q.front()],q.pop_front();
			f[j]=sum;
			if (f[j]==2){
				ans++;
			}
			if (a[j+1]-a[id]>d){
				for (int k=lst;k<=j;k++)q.push_back(k),sum+=f[k];
				lst=j+1;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>fw>>t;
	while (t--){
		act();
	}
	return 0;
}
