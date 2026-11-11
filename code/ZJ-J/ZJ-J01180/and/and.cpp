#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(a[i],ans);
		cout<<ans;
	}
	else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++)ans&=a[i];
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			ll cnt=0;
			ans=a[1];
			for(int j=1;j<=n;j++){
				if(i!=j)ans&=a[j];
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
}