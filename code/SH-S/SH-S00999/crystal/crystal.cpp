#include<bits/stdc++.h>
using namespace std;
#define fre(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define int long long
const int N=5e5+19;
int n,m,a[N],s[N];
bool check(int i,int mid){
	return (mid-1)*a[i]-(s[i-1]-s[i-(mid-1)-1])<=m;
}
signed main(){
	fre(crystal);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int maxx=1;
	for(int i=1;i<=n;i++){
		int l=0,r=i,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
