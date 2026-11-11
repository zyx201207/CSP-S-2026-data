#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=5e5+10;

ll n,m;
ll a[maxn];
ll sum[maxn];
ll anss;

int check(ll x,ll w){
	return (a[w]*(w-x+1)-(sum[w]-sum[x-1])<=m);
	
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	
	}

	for(int i=1;i<=n;i++){
		ll L=1,R=i;
		ll ans=0;
		while(L<=R){
			ll mid=(L+R)>>1;
			if(check(mid,i)){
				R=mid-1;
				ans=mid;
			}else{
				L=mid+1;
			}
		}
		
		
		anss=max(anss,i-ans+1);
	}
	cout<<anss<<endl;
	
	return 0;
}


