#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=0;
ll a[500005]; 
ll b[5005][5005];
ll c[500005];
ll d[500005];
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<n<<" "<<m<<endl;
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			b[j][i]=a[i]-a[j];
		}
	}
	for(int i=2;i<=n;i++){
		ll cnt=0;
		for(int j=i-1;j>=1;j--){
			if(c[i]+b[j][i]<=m){
				c[i]+=b[j][i];
				//cout<<cnt<<endl;
				cnt++;
			}else{
				d[i]=cnt;
				break;
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<<c[i]<<" "<<d[i]<<" "<<endl;
	}
	*/
	ll mx=0;
	for(int i=2;i<=n;i++){
		if(d[i]>=mx) mx=d[i];
	}
	cout<<mx<<endl;
	return 0;
}
