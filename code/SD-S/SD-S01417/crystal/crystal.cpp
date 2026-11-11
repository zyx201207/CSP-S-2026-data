//SQKS
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,a[500010];
int mg;
ll s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1ll,r=(ll)(i-1);
		ll pos=i;
		while(l<=r){
			ll mid=l+r>>1;
			if(((ll)i-mid)*a[i]-s[i-1]+s[mid-1]<=m)pos=mid,r=mid-1;
			else l=mid+1;
		}
		mg=max(mg,i-(int)pos+1);
	}
	cout<<mg;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
