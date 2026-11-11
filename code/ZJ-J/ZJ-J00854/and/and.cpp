#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int n,m,a[200005],ans,res,st,p[200005];
bool cnt[200005][31];
queue<int> q;
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		for(int j=0;j<=30;j++) {
			if(a[i]&1) cnt[i][j]=true;
			a[i]>>=1;
		}
	}
	for(int i=30;i>=0;i--) {
		int res=0;
		for(int j=1;j<=n;j++) {
			if(cnt[j][i]==true) {
				++res;
			}
		}
		if(res>=m) {
			st=i-1;
			ans+=(1<<i);
			for(int j=1;j<=n;j++) {
				if(cnt[j][i]==true) {
					q.push(j);
				}
			}
			break;
		}
	}
	for(int i=st;i>=0;i--) {
		int res=0,num=0;
		while(!q.empty()) {
			int t=q.front();q.pop();
			p[++num]=t;
			if(cnt[t][i]) {
				++res;
			}
		}
		if(res>=m) {
			ans+=(1<<i);
			for(int j=1;j<=num;j++) {
				if(cnt[p[j]][i]==true) {
					q.push(p[j]);
				}
			}
		} else {
			for(int j=1;j<=num;j++) {
				q.push(p[j]);
			}
		}
	}
	cout<<ans;
	return 0;
}