#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e6+10,MOD=1e9+7;
int n,size,a[N],m,flag1=1,b[N],ans,maxx;
signed main(){
	IOS
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(i!=1){
			b[i]=a[i-1];
		}
		if(a[i]!=i-1) flag1=0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			int sum=a[i];
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(sum&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==m){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m=n-1){
		int k=a[1];
		for(int i=1;i<=n;i++){
			k&=a[i];
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,k|a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(flag1){
		ans=a[1];
		for(int i=1;i<n;i*=2){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	cout<<maxx;
	return 0;
}
