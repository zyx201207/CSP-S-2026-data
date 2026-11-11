#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int d[N];
int f[N];
int b[N];
int ta=0;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i-1]>a[i])
			ta=1;
	}
	if(ta==0) {
		for(int i=1; i<=n; i++) {
			b[a[i]]++;
		}
		for(int i=1; i<=n; i++) {
			d[a[i]]=max(d[a[i]],i);
		}
		for(int i=1; i<=m; i++) {
			cout<<d[i]<<' ';
		}
		return 0;
	}
	for(int j=1; j<=n; j++) {
		memset(f, 0, sizeof f);
		stack<int>s;
		for(int i=j; i<=n; i++) {
			if(f[a[i]]==1) {
//				cout<<'a'<<a[i]<<' ';
				while(s.top()!=a[i]) {
					f[s.top()]=0;
					d[s.top()]--;
					s.pop();
				}
			} else {
				f[a[i]]=1;
				d[a[i]]++;
				s.push(a[i]);
			}
		}
//		for(int i=1;i<=m;i++){
//			cout<<d[i]<<' ';
//		}
//		cout<<'\n';
	}
	for(int i=1; i<=m; i++) {
		cout<<d[i]<<' ';
	}
	return 0;
}
/*

10 5
1 1 1 2 3 3 5 5 5 5

*/
