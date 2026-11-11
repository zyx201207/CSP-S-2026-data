#include<bits/stdc++.h>
#define ll long long  
using namespace std;
const int NN=5*1e5+10;
ll n,m;
ll a[NN];
bool cmp(long long a,long long b){
	return a>b;
}
ll temp;
ll ans=0;
ll now;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<n;++i){
		//cout<<"当前基准数为： "<< a[i]<<endl;
		now=m;
		ll j;
		for(j=i+1;j<=n;j++){
			//cout<<"当前数为： "<<a[j]<<endl; 
			//cout<<"当前能量值为： "<<now<<endl; 
			if((a[i]-a[j])>now){
				break;
			}else {
				now-=(a[i]-a[j]);
				continue;
			}
		}
		ans=max(ans,j-i);
		//cout<<"当前最大值为： "<<ans<<endl; 
	}
	cout<<ans;
    return 0;
}


