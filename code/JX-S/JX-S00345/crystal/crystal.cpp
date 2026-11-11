#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,mod=998244353;
int n,m;
int a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=0,ans=1;
	for(;r<=n;r++){
		while(a[r]*(r-l+1)-s[r]+s[l-1]>m)l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

14:30 
O(n^2)
45pts

14:54
O(nlogn) (sort nlogn+2-point n)
100pts
*/