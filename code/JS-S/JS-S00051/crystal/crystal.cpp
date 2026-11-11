#include<bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=500009;
int n,l,r,ans;
ll m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(r=1;r<=n;r++){
		while((r-l)*a[r]-(s[r]-s[l])>m) l++;
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
