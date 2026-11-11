#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],t;
map<int,int>mp;
int pd(int x) {
	int xb=0;
	for(int i=1;i<=t;i++) 
		if(a[i]==x) {
			xb=i;
			break;
		}
	return xb;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b[i];
	if(m==2) {
		for(int i=1;i<=n;i++) {
			if(b[i]==1) {
				mp[1]++;
				if(b[n]==2) mp[2]++;
			}
			if(b[i]==2) {
				mp[2]++;
				if(b[n]==1) mp[1]++;
			}
		}
		cout<<mp[1]<<" "<<mp[2];
		return 0;
	}
	for(int i1=1;i1<=n;i1++) {
		t=0;
		for(int i=i1;i<=n;i++) {
			int sb=pd(b[i]);
			if(sb==0) {
				t++;
				a[t]=b[i];
			}
			else {
				t=sb-1;
				t++;
				a[t]=b[i];
			}
		}
		for(int j=1;j<=t;j++) mp[a[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<mp[i]<<" ";
	return 0;
}
