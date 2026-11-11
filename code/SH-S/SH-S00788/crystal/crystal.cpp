#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		if((a[i+1]-a[i])*i<=m){
			ans++;
			m-=((a[i+1]-a[i])*i);
		}
		else
			break;
	}
	cout<<ans<<endl;
	return 0;
}
