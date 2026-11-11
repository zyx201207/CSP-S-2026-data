#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
int n,m;
const int N=5e5+5, M=3e5;
int a[N];
int del[N];//first delete pos
int cur[N];
int len;
int pos[N];//number pos
int ans[M+5];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		len=0;
		memset(pos, 0, 4*n+10);
		for(int j=i;j<=n;j++) {
			for(int k=1;k<=len;k++) if(cur[k]==a[j]) {
				len=k-1;
				break;
			}
			cur[++len]=a[j];
		}
		for(int j=1;j<=len;j++) ans[cur[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
