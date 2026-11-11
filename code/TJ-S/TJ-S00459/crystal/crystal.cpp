#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
ll n,m;
ll cha=0;
bool check(int i){
	ll k=0;
	for(int j=1;j<=i;j++){
		k+=(a[i]-a[j]);
		if(k>m)return 0;
	}
	return 1;
}
void AB(){
	if((m/cha)%2)cout<<m/cha/2+1;
	else cout<<m/cha/2;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	bool flag=1;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==2){
			cha=a[2]-a[1];
		}else if(i!=1){
			if((a[i]-a[i-1])!=cha)flag=0;
		}
	}
	if(flag){
		AB();
		return 0; 
	}
	sort(a+1,a+n+1);
	ll ans=1;
	for(ll i=1;i<=n;i++){
		if(check(i))ans=i;
		else break;
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

