#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m;
ll a[N],ans=0,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	else if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==2){
		for(ll i=1;i<=n-1;i++){
			for(ll j=i+1;j<=n;j++){
				ans=max(ans,i&j);
			}
		}
		cout<<ans;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			if(i==1) k=a[2];
			else k=a[1];
			for(int j=1;j<=n;j++) if(j!=i) k=k&a[j];
			ans=max(ans,k);
		}
	}
	cout<<ans;
	return 0;
}

