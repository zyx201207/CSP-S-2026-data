#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+20;
int n,m;
int a[N];
void sol(){
	cin >>n>>m;
	for(int i=1;i<=n;i++)
		cin >>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,k=a[1],ans=0;
	while(r<=n){
		while(r<n&&k+m+a[r+1]>=a[r+1]*(r+1-l+1))r++,k+=a[r];
		ans=max(r-l+1,ans);
		k-=a[l];l++;
		if(l>n)break;
		if(l>r)r=l,k=a[l];
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
//	cin >>t;
	while(t--)
		sol();
}
