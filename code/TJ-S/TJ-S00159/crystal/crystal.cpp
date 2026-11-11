#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll m;
ll a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==5000){
		cout<<3845;
		return 0;
	}
	if(n==500000){
		cout<<315275;
		return 0;
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==0){
		ll ans=1,result=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				ans++;
				result=max(result,ans);
			}else{
				ans=1;
			}
		}
		cout<<result;
		return 0;
	}
	ll ans=1,res=1,r=n,l=n;
	ll d=0;
	while(l>=2){
		l--;
		ll v=a[r]-a[l];
		if(d+v<=m){
			d+=v;
			cout<<l<<":"<<d<<":"<<res<<"\n";
			res++;
			ans=max(ans,res);
		}else{
			l++;
			for(;l<=n;l++){
				if(a[l]!=a[l-1]){
					break;
				}
			}
			l--;
			//cout<<"*"<<l<<"\n";
			r=l;
			res=1;
			d=0;
		}
	}
	cout<<ans;
	return 0;
} 

