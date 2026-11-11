#include<bits/stdc++.h>
using namespace std;
#define int long long
using ull=unsigned long long;
const int N=5e5+10;
int n,m;
int a[N];
ull sum[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag1=true;
	int delta=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flag1=false;
	}
	if(flag1){
		ull tmp=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			tmp+=i-1;
			if(tmp>(ull)m){
				ans=i-1;
				break;
			}
		}
		if(tmp<=(ull)m)ans=n;
		cout<<ans<<"\n";
		return 0;
	}
	delta=a[2]-a[1];
	bool flag2=true;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=delta)flag2=false;
	}
	if(flag2){
		ull tmp=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			tmp+=i-1;
			if(delta*tmp>(ull)m){
				ans=i-1;
				break;
			}
		}
		if(delta*tmp<=(ull)m)ans=n;
		cout<<ans<<"\n";
		return 0;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		ull tmp=0;
		for(int k=i;k>=1;k--){
			tmp+=a[i]-a[k];
			if(tmp>(ull)m){ans=max(ans,i-k);break;}
		}
		if(tmp<=(ull)m)ans=max(ans,i);
	}
	cout<<ans<<"\n";
	return 0;
}
/*

*/


