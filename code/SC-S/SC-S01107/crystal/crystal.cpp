#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],b[N],c[N],ans;
ll n,m;
void check(ll x,ll d){
	while(d){
		if(c[x]<=m)x+=d;
		else if(c[x]>m)x-=d;
		d/=2;
	}
	//if(c[x]>m)x-=1;
	ans=x;
	return;
}

int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
		
	for(int i=1;i<n;i++)b[i]=a[i]-a[0];
	c[1]=b[1];
	for(int i=2;i<n;i++)c[i]=c[i-1]+b[i];
	
	if(c[n-1]<=m)cout<<n;
	else{
		check((n-1ll)/2,(n-1ll)/4);
		cout<<ans;
	}	
	return 0;
}