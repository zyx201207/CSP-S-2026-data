#include<bits/stdc++.h>
using namespace std;
signed int a[200010];
vector<signed int>cnt[35];
vector<signed int>newcnt[35];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		signed int x=a[i];
		int now=0;
		while(x) {
			if(x&1) {
				cnt[now].push_back(a[i]);
			}
			x/=2;
			now++;
		}
	}
	signed int ans=0;
	for(int k=30; k>=0; k--) {
		for(int i=0;i<=30;i++){
			newcnt[i].clear();
		}
		if(cnt[k].size()>=m) {
			for(auto i:cnt[k]) {
				signed int x=i;
				int now=0;
				while(x) {
					if(x&1) {
						newcnt[now].push_back(i);
					}
					x/=2;
					now++;
				}
			}
			swap(newcnt,cnt);
			ans+=(1<<k);
		}
	}
	cout<<ans;
	return 0;
}
