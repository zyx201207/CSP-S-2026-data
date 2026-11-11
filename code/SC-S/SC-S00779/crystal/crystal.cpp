#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
ll a[600010];
int bp;
ll cnt,rem;
void d(ll x){
	if(cnt==m) {
		bp=x;
		return;
	}
	if(x!=a[rem]){
		if(x/2>a[rem]){
			cnt++;
			x=x/2;
			ans++;
			cout<<ans<<"?";
			d(x);
		}
		else{
			cnt++;
			x--;
			d(x);
		}
		
	}
	else{
		rem--;
		ans++;
		d(x);
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rem=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	d(a[n]);
	cout<<ans;
    return 0;
}


