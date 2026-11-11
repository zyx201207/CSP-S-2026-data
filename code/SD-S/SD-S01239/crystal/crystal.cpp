#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int Max=5e5+10;
const ll Min=1e12+10;
int n,ans=0;
ll a[Max],m,minn=Min,maxn=-Min;
bool cmd(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(minn>a[i])minn=a[i];
		if(maxn<a[i])maxn=a[i];
	}
	sort(a+1,a+1+n,cmd);
	ll l=minn,r=maxn;
	while(l<r){
		ll bao=m;
		ll mid=(l+r)/2;
		int ansbao=0;
		for(int i=1;i<=n;i++){
			if(a[i]>mid)continue;
			if(a[i]==mid){
				ansbao++; 
				continue;
			}	
			ll aaa=mid-a[i];
			if(bao>0){
				bao=bao-aaa;
				ansbao++;
			}
		}
		ans=ansbao;
		if(bao==0||l+1==r)break;
		else if(bao>0)l=mid;
		else r=mid;
	}
	cout<<ans;
	return 0;
}
