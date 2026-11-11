#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e4+10;
ll n,m;
ll a[N];
ll maxx=-1e18;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		ll b[N];
		for(int j=1;j<=n;j++){
			b[j]=a[i]-a[j];
		}
		sort(b+1,b+n+1);
		ll ans=0,m1;
		m1=m;
		for(int j=1;j<=n;j++){
			if(b[j]>=0 && b[j]<=m1){
				m1-=b[j];
				ans++;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
