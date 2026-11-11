#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
bool f[maxn];
int a[maxn];
int ans[maxn];
int b[maxn];
int n,m;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	
	for (int i=1;i<=n;i++) {
		int j=1;
		stack<int>stk;
		memset(b,0,sizeof (b));
		memset(f,0,sizeof (f));
		for (;j<=i-1;j++) {
			f[a[j]]=1;
			stk.push(a[j]);
			b[a[i]]++;
		}
		for (;j<=n;j++) {
			if (f[j]==0) {
				stk.push(a[j]);
			} else {
				while (!stk.empty()&&stk.top()!=a[j]) {
					b[stk.top()]--;
					if (b[stk.top()]==0) f[stk.top()]=0;
					stk.pop();
				}
				stk.pop();
				stk.push(a[j]);
				b[a[j]]++;
				f[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++) {
			if (f[j]==1) ans[j]++;
		}
	}
	for (int i=1;i<=m;i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}

