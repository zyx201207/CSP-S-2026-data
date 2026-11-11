#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
deque<pair<int,char> >q;
signed main(void) {
	IOS;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int x;
		char c;
		cin>>x>>c;
		q.push_back({x,c});
	}
	int ans=0;
	while(!q.empty()) {
		int qx=q.front().first,hx=q.back().first;
		char qc=q.front().second,hc=q.back().second;
		q.pop_front();
		if(!q.empty())
			q.pop_back();
		if(qc==hc) {
			if(qx>hx) {
				q.push_front({qx-hx,qc});
			} else if(qx<hx) {
				q.push_back({hx-qx,hc});
			} else if(qx==hx) {
			}
		} else {
			if(qx>hx) {
				ans+=hx;
				q.push_front({qx-hx,qc});
			} else if(qx<hx) {
				ans+=qx;
				q.push_back({hx-qx,hc});
			} else if(qx==hx) {
				ans+=hx;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
