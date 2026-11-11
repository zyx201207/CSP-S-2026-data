#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n,maxx;
ll a[N],s[N],m;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		s[i]=s[i+1]+a[i];	
	}
	for(int i=n;i>=1;i--){
		int l=1,r=i,ans=0;
		ll nw=s[i];
		while(l<=r){
			int mid=(l+r)>>1;
			if(1ll*(i-mid)*a[i]-(s[mid]-nw)<=m) ans=mid,r=mid-1;
			else l=mid+1;
		}
		maxx=max(maxx,i-ans+1);
	}
	cout<<maxx;
	return 0;
}
/*
#1
5 5
1 2 4 8 9

#2
5 8
-3 -1 2 2 7

*/
