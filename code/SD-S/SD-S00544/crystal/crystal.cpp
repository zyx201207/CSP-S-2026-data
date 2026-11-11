#include<iostream>//T1 100
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	ll ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1;
	for(int r=2;r<=n;r++){
		ll d=a[r]-a[r-1];
		ll len=r-l;
		while(d*len>m){
			m+=a[r-1]-a[l];
			l++;
			len--;
		}
		m-=d*len;
		ans=max(len+1,ans);
	}
	cout<<ans<<endl;
	return 0;
}
