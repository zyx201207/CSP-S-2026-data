#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int f[500010],s[500010];
bool kk[500010],ans[500010];
int main () {
	ios::sync_with_stdio(0);cin.tie(NULL),cout.tie(NULL);
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) {
		memset(f,0,sizeof f);
		memset(kk,0,sizeof kk);
		memset(ans,0,sizeof ans);
		for (int j=i;j<=n;j++) {	
			if (f[a[j]]) 
				for (int l=f[a[j]];l<=j-1;l++ ) {
					if (!kk[l]) {
						f[a[l]]=false;	
						ans[l]=true;
					}
					kk[l]=true;
				}
			f[a[j]]=j;
		}
		for (int j=i;j<=n;j++) 
			if (!ans[j]) 
				s[a[j]]++;
	}
	for (int i=1;i<=m;i++) 
		cout<<s[i]<<' ';
}
//4 3
//1 2 1 3
//10 3
//3 1 2 1 3 2 3 1 2 1
