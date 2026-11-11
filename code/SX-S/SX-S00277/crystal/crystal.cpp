#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,e[550000];

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	for(int i=1; i<=n; ++i)
		cin>>e[i];
	sort(e+1,e+n+1);
	int mx=1,maxx=1,t,cnt;
	for(int i=1; i<n; ++i) {
		if(e[i]==e[i+1]) {
			mx++;
			maxx=max(maxx,mx);
		} else
			mx=1;
	}
	if(maxx==1) {
		t=1;
		cnt=1;
		while(true) {
			int de=e[t+1]-e[t];
			if(m>=de*t) {
				m-=de*t;
				cnt++;
				t++;
			} else {
				cout<<cnt<<'\n';
				break;
			}
		}
	} else {
		int mxb=1,ta;
		for(int i=1; i<n; ++i) {
			if(e[i]==e[i+1])
				mxb++;
			else
				mxb=1;
			if(mxb==maxx) {
				if(i!=(maxx-1))
					ta=i-maxx+1;
				else
					ta=i+2;
				break;
			}
		}
		t=ta;
		cnt=maxx;
		while(true) {
			int de=e[t+1]-e[t];
			if(t<=ta) {
				if(m>=de*(ta-t+1)) {
					m-=de*(ta-t+1);
					cnt++;
					if(t==1)
						t=ta+maxx;
					else
						t--;
				} else {
					cout<<cnt<<'\n';
					break;
				}
			} else {
				if(m>=de*t) {
					m-=de*t;
					cnt++;
					t++;
				} else {
					cout<<cnt<<'\n';
					break;
				}
			}
		}
	}
	return 0;
}
