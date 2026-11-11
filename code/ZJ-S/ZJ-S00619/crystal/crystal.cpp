#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int A=1,B=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1])B=0;
	}
	if(A||B){
		ll ans=0;
		for(int i=n;i>=1;i--){
			m-=(a[n]-a[i]);
			if(m<0){
				break;
			}else{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	ll mx=0;
	for(int i=1;i<=n;i++){
		ll ans=1;
		ll k=m;
		for(int j=i-1;j>=1;j--){
			int x=a[i]-a[j];
			k=k-x;
			if(k<0){
				break;
			}else{
				ans++;
			}
		}
		mx=max(mx,ans);
	}
	cout<<mx<<endl;
	return 0;
}