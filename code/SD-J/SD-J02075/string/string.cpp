#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int __=1;
int n,ans,l,r;
int a[N];
char c[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<=r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				//cout<<ans<<"\n";
				ans+=a[l];
			}
			a[r]-=a[l];l++;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r]){
				//cout<<ans<<"\n";
				ans+=a[r];
			}
			a[l]-=a[r];r--;
		}else{
			if(c[l]!=c[r]){
				//cout<<ans<<"\n";
				ans+=a[r];
			}
			r--,l++;
		}
	}
	cout<<ans;
	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//cin>>__;
	while(__--) solve();
	return 0;
}
//十年oi一场空，不开long long见祖宗 
