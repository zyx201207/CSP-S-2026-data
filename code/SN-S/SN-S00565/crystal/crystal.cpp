#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,a[N],flag,b[N],ans,ans2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=i+b[i-1];
	}
	for(int i=1;i<=n;i++){
		if(i!=1){
			if(a[i]-a[i-1]!=a[2]-a[1]){
				flag=1;
			}
		}
	}
	if(flag==0){
		ll k=a[2]-a[1];
		for(int i=1;i<=n;i++){
			ll l=upper_bound(b+1,b+n+1,m/k)-b;
			l--;
			ans2=max(ans2,l);
		}
		cout<<ans2+1<<"\n";
	}
	else{
		for(int i=1;i<=n;i++){
			ll k=m,cnt=0;
			for(int j=i;j>=1;j--){
				if(k>=a[i]-a[j]){
					cnt++;
					k=k-(a[i]-a[j]);
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
