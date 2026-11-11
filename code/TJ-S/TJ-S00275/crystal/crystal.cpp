#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+3;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);	
	freopen("crystal.out","W",stdin);
	int n,m;
	cin>>n>>m;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f=false;
	}
	if(f==true){
		ll l=1,r=2e9;
		ll cha=a[2]-a[1];
		while(l<=r){
			ll mid=(l+r)/2;
			ll k=(mid*cha+cha)*mid/2;
			if(k>m) r=mid-1;
			else l=mid+1;
		}
		cout<<r+1;
	}
	else{
		sort(a+1,a+n+1);
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll sum=0;
			for(int j=1;j<=i;j++){
				sum+=a[i]-a[j];
			}
			if(sum<=m) ans=i;
			else break;
		}
		cout<<ans;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
