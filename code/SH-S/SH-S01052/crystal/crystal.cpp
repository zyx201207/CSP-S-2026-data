#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll n,m,a[N],qz[N],ans,cnt[N],bf[5009][5009],ii,sl;
bool oka,okb;
void solve_BF(){
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			bf[i][j]=a[j]-a[i];
		}
	}
	for(ll i=2;i<=n;i++){
		sl=1;
		for(ll j=i;j<=n;j++){
			cnt[i]+=sl*qz[j];
			sl++;
			//cout<<cnt[i]<<" ";
			if(cnt[i]>m){
				ans=max(sl-1,ans);
				break;
			}
			if(j==n){
				ans=max(ans,sl);
			}
		}
	}
	cout<<ans;
}
void solve_okb(){
	ll cha1=a[2]-a[1],cha=cha1;
	while(m>=0){
		m-=cha;
		cha+=cha1;
		ans++;
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	oka=1,okb=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3){
			if((a[i]-a[i-1])!=(a[i-1]-a[i-2])){
				okb=0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		qz[i]=a[i]-a[i-1];
	}
	if(n<=5000){
		solve_BF();
		return 0;
	}
	else if(okb==1){
		solve_okb();
		return 0;
	}
	return 0;
}
