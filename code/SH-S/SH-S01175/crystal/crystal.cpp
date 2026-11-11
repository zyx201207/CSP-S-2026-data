#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll maxn=5e5+5;

ll n,m;
ll a[maxn],lsh[maxn],tru[maxn],d[maxn],sumd[maxn];

bool check(ll x){
	for(int i=2;i<=n-x+1;i++){
		ll tmp=0;
		for(int j=0;j<=x-1;j++){
			tmp+=sumd[i+x-2]-sumd[i+j-1];
		}
		if(tmp<=m) return true;
	}
	return false;
}
bool checks(ll x){
	if((d[2]*x*(x-1)/2)<=m) return true;
	else return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	sumd[1]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	d[1]=0; sumd[1]=0;
	
	sort(a+1,a+n+1);
	//ll cnt=0;
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
        sumd[i]=d[i]+sumd[i-1];
		//cout<<sumd[i]<<" "<<endl;
	}
	bool flg=true;
	for(int i=3;i<=n;i++){
		if(d[i]!=d[i-1]){
			flg=0;
			//cout<<i<<endl;
		} 
	}
	if(flg){
		ll l=1,r=n,ans=1;
		while(l<=r){
			ll mid=(l+r)/2;
			if(checks(mid)){
				ans=mid;
				l=mid+1;
				//cout<<"check"<<mid<<endl;
			}
			else{
				//cout<<"check"<<mid<<endl;
				r=mid-1;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	ll l=1,r=n,ans=1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			//cout<<"check"<<mid<<endl;
			r=mid-1;
		}
	}
	cout<<ans<<endl;
}
