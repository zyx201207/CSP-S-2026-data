#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000002],b[1000002],c[1000002],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		b[i]*=(i-1);
		c[i]=c[i-1]+b[i];
	}
	for(int i=2;i<=n;i++){
		if(c[i]<=m){
			ans=i;
		}
		else{
			break;
		}
		
	}
	cout<<ans<<endl;
	
	return 0;
}

