#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll n,m,a[N],andai,maxai=0,to2[N][40],size2[N];
void to_10_2(ll x,ll i){
	ll y=0;
	while(x){
		to2[i][++y]=x&1;
		x/=2;
	}
	size2[i]=y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxai=max(maxai,a[i]);
		to_10_2(a[i],i);
	}
	andai=a[1];
	for(ll i=2;i<=n;i++)
		andai&=a[i];
	if(m==1){//ÌØÅÐ 1£ºm==1
		cout<<maxai;
		return 0;
	}
	else if(m==n){//ÌØÅÐ 2£ºm==n
		cout<<andai;
		return 0;
	}
	else if(m==2){//ÌØÅÐ 3£ºm==2
		ll maxx=0;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				if(i!=j)
					maxx=max(maxx,a[i]&a[j]);
		cout<<maxx;
	}
	cout<<0;
	return 0;
}
