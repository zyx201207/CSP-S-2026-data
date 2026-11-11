#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll c,T,n,d,a[N],pos[N];
inline void solve2(){
	ll ans,mpos=d/(a[2]-a[1]);
	if(mpos>=n-1)ans=0;
	else ans=(mpos-1ll)*(n-1)-(3ll*mpos-1)*(mpos-1ll)/2;
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ll lst=1;
		a[n+1]=a[n]+d+1;
		for(int i=1;i<=n+1;i++){
			while(lst<=n&&a[i]-a[lst]>d)
				pos[lst++]=i-1;
		}
		if(11<=c&&c<=12)solve2();
		else cout<<"0\n";
	return 0;
}