#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,cnt,maxn;
int a[N];
int l,r;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1,r=1;
	while(l<=n){
		while(r<n&&cnt+(a[r+1]-a[r])*(r-l+1)<=m){
			r++;
			cnt+=(a[r]-a[r-1])*(r-l);
		}
		if(r<l){
			r=l;
			cnt=0;
		}
		maxn=max(maxn,r-l+1);
		cnt-=a[r]-a[l];
		l++;
	}
	cout<<maxn;
	return 0;
}