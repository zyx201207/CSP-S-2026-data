#include <bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,r,l) for(int i=(r);i>=(l);i--)
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll a[N],m,s[N];
bool check(int len){
	For(i,len,n)
		if(m+s[i]-s[i-len]>=len*a[i]) return 1;
	return 0;
}signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	For(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	For(i,1,n) s[i]=a[i]+s[i-1];
	int l=2,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}cout<<l-1<<"\n";
	return 0;
} //1450
