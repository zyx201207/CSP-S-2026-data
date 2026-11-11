#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+10;
int n,m,mx;
int a[N],s[N];
bool check(int x,int pos){
	return x*a[pos]-s[pos-1]+s[pos-x-1]<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i-1,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		mx=max(mx,ans+1);
	}
	cout<<mx;
	cout<<flush;
	fclose(stdin),fclose(stdout);
	return 0;
}
