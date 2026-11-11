#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1114514],m;
int ans[1114514];
int jpq[1114514];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int k=1; k<=n; k++) {
		stack<int> s;
		memset(jpq,0,sizeof(jpq));
		for(int i=k; i<=n; i++) {
			if(i==k) {
				s.push(a[i]);
				jpq[a[i]]=1;
			} else {
				if(jpq[a[i]]==1) {
					while(1) {
						if(s.top()==a[i]) {
							break;
						} else {
						 	jpq[s.top()]=0;
							s.pop();

						}
					}
				}
				s.push(a[i]);
				jpq[a[i]]=1;
			}

		}
		for(int i=1; i<=m; i++) {
			if(jpq[i]==1){
				ans[i]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//  调了40分钟没调出来 
