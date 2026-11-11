#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m;
ll a[N],s[N];
ll ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=a[i]-a[i-1];
	ll ans=-1;
	ll i=1,j=1;
	ll op=0,len=1;
	while(i<=n){
		while(op<=m&&i<=n){
			i++;
			ans=max(ans,len);
			op+=len*s[i];
			len++;
		}
		while(op>m&&j<i){
			op-=a[i]-a[j];
			j++;
			len--;
		}
	}
	cout<<ans;
	return 0;
} 
