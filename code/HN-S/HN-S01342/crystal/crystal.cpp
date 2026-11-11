#include<bits/stdc++.h>
using namespace std;
#define ll long long


const int N=5e5+5;
ll a[N];
ll cha[N];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int z;
	if(n%2==0){
		z=a[n/2]+(a[n/2+1]-a[n/2])/2;
	}
	else{
		z=a[n/2+1];
	}
	for(int i=1;i<=n;++i){
		cha[i]=abs(a[i]-z);
	}
	sort(cha+1,cha+n+1);
	ll ans=0;
	int now=1;
	while(m-cha[now]>=0){
		m-=cha[now];
		ans++;
		now++;
	}
	cout<<ans;
	return 0;
}
