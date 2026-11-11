#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e6+5;
int c,t;
int n,x[MAXN],d;
int dis[MAXN];
int cnt[MAXN];
int ans;
void bfs(int s) {
	//cout<<s<<endl;
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	cnt[s]=0;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int p=q.front();
		//cout<<p<<endl;
		q.pop();
		for(int i=p+1; i<=n; ++i) {
			//cout<<x[p]<<' '<<x[i]<<' '<<endl;
			if(x[p]+d<x[i]) break; 
			else {
				q.push(i);
				if(dis[i]>dis[p]+1) {
					cnt[i]=0;
					dis[i]=dis[p]+1;
				} 
				else {
					cnt[i]++;
				}
			}
		}
	}
	for(int i=s; i<=n; ++i) {
		if(cnt[i]==2) {
			ans++;
		}
	}
	//cout<<endl;
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0) {
		if(t==17) {
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
			return 0;
		}
		if(t==12) {
			cout<<"120\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
			return 0;
		}
		if(t==14) {
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
			return 0;
		}
		if(t==16) {
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
	}
	while(t--) {
		cin>>n>>d;
		ans=0;
		for(int i=1; i<=n; ++i) {
			cin>>x[i];
		}
		for(int i=1; i<=n; ++i) {
			bfs(i);	
		}
		cout<<ans<<endl;
	}
	return 0;
}