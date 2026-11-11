#include"iostream"
#include"cmath"
#include"algorithm"
using namespace std;
#define ll long long
const ll N=5e5+5;
ll a[N],b[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	b[0]=0;
	cin>>a[1];
	b[1]=a[1];
	for(ll i=2;i<=n;++i){
		cin>>a[i];
		b[i]+=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i){
		if(((b[i]+m)/i>=a[i]||(b[i-1]+m)/i==a[i])){
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}