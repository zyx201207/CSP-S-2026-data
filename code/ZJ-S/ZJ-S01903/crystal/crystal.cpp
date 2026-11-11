#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll a[500010],m,n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	//AB
	bool cha=1;
	int gc=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=gc){
			cha=0;
		}
	}
	if(cha){
		ll ans=0;
		while(m>gc*ans){
			m-=gc*ans;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	//1-9
	ll maxx=-1;
	for(int i=1;i<=n;i++){
		if(i+maxx>=n){
			break;
		}
		ll ans=1,ans1=0;
		for(int j=i+1;j<=n;j++){
			if(ans1>m){
				if(maxx<ans-1){
					maxx=ans-1;
				}
			}else{
				ans1+=(a[j]-a[j-1])*ans;
				ans++;
			}
		}
		if(ans1>m){
			if(maxx<ans-1){
				maxx=ans-1;
			}
		}
	}
	cout<<maxx;
	return 0;
}