#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
signed main( ){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int pos=1,k=0;
	for(int i=2;i<=n;i++){
		if((k+(a[1]-a[i]))<=m) pos=i,k+=(a[1]-a[i]);
		else break;
	}
	int maxn=pos; k=m-k;
	for(int i=2;i<=n;i++){
		k+=(a[i-1]-a[i]); k+=(pos-i)*(a[i-1]-a[i]);
		while((k-(a[i]-a[pos+1]))>=0&&pos<n) pos++,k-=(a[i]-a[pos]);
		maxn=max(maxn,pos-i+1);
	}
	cout<<maxn;
	return 0;
} 
