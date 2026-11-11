#include<bits/stdc++.h>
using namespace std;
int n,m;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	if(n<=500) {
		int a[520],pos[520],q[520],res[520];
		memset(a,0,sizeof(a));
		memset(pos,0,sizeof(pos));
		memset(q,0,sizeof(q));
		memset(res,0,sizeof(res));
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=1; i<=n; i++) {
			int t=0;
			memset(q,0,sizeof(q));
			memset(pos,0,sizeof(pos));
			for(int j=i; j<=n; j++) {
				if(pos[a[j]]!=0) {
					while(t>pos[a[j]]) {
						pos[q[t]]=0;
						t--;
					}
				} else {
					q[++t]=a[j];
					pos[a[j]]=t;
				}
			}
			for(int i=1; i<=t; i++) res[q[i]]++;
		}
		for(int i=1; i<=m; i++) cout<<res[i]<<" ";
	} else if(n<=5000) {
		int a[5020],pos[5020],q[5020],res[5020];
		memset(a,0,sizeof(a));
		memset(pos,0,sizeof(pos));
		memset(q,0,sizeof(q));
		memset(res,0,sizeof(res));
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=1; i<=n; i++) {
			int t=0;
			memset(q,0,sizeof(q));
			memset(pos,0,sizeof(pos));
			for(int j=i; j<=n; j++) {
				if(pos[a[j]]!=0) {
					while(t>pos[a[j]]) {
						pos[q[t]]=0;
						t--;
					}
				} else {
					q[++t]=a[j];
					pos[a[j]]=t;
				}
			}
			for(int i=1; i<=t; i++) res[q[i]]++;
		}
		for(int i=1; i<=m; i++) cout<<res[i]<<" ";
	}
	return 0;
}

