#include <bits/stdc++.h>
using namespace std;
int n,m,t,T;
int a[500010],mp[300010],ans[500010],desktop[500010];
bool SubtaskA;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	SubtaskA=true;
	for (int i=1;i<n;i++) {
		if (a[i]<=a[i+1]) ;
		else SubtaskA=false;
	}
	if (SubtaskA) {
		for (int i=1;i<=n;i++) mp[a[i]]++;
		for (int i=1;i<=m;i++) mp[i]+=mp[i-1];
		for (int i=1;i<=m;i++) cout<<mp[i]<<" ";
		return 0;
	}
	T=1;
	for (int T=1;T<=n;T++) {
		t=0;
		memset(desktop,0,sizeof(desktop));
		memset(mp,0,sizeof(mp));
		for (int i=T;i<=n;i++) {
			if (mp[a[i]]) {
				int tmp=mp[a[i]];
				for (int j=mp[a[i]];j<=t;j++) mp[desktop[j]]=0;
				t=tmp-1;
			}
			t++;
			desktop[t]=a[i];
			mp[a[i]]=t;
		}
		for (int i=1;i<=t;i++) ans[desktop[i]]++;
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
