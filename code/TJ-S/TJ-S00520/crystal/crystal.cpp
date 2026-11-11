#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
const int MINI=-2*1e5-1;
int cnt=0;
int ansi=0;
int ma=MINI;
int ans[N];
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+1+n);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			cnt=0;
			for(int k=i;k<=j;k++) cnt+=a[j]-a[k];
			if(cnt<=m) ans[++ansi]=j-i+1;
		}
	}
	for(int i=1;i<=ansi;i++) ma=max(ma, ans[i]);
	cout<<ma;
	return 0;
}

