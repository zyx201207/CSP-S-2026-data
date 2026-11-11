#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,a[N],s[N],m,ans;
bool check(int x,int f){
	return m>=(s[x]-s[f])-(a[x]-a[f])*(f-1);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cout.tie(nullptr)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)) l=mid+1;
			else r=mid-1; 
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans-1;
	return 0;
}