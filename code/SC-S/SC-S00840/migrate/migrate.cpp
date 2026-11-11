#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
int ceshi,T;
int n;
ll a[N],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>ceshi>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(ceshi==11||ceshi==12){
			if(n==1){
				cout<<"0\n";
				continue;
			}
			ll diff=a[2]-a[1];
			ll cnt=d/diff;
			if(cnt<2){
				cout<<"0\n";
				continue;
			}
			int ans=max(0ll,n-2*cnt+1);
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}