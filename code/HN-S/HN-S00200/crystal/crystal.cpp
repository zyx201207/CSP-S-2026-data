#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kMaxN=5e5+5;
int n,m;
int a[kMaxN];
int maxn=LLONG_MIN;
int f[kMaxN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,sum=0;
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l+1);
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		}
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn;
	return 0;
}
