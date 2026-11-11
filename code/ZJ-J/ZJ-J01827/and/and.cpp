#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],mx=1,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&=a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			mx=1;
			for(int j=1;j<=17;j++){
				mx*=2;
			}
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				mx&=a[j];
			}
			ans=max(mx,ans);
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<1;
	}
}
