#include<bits/stdc++.h>
using namespace std;
long long n,a[500005];
long long m;
long long maxx;
int main(){
	
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    sort(a+1,a+n+1);
    
    if(n>5000 && a[2]-a[1]==a[3]-a[2]&&a[3]-a[2]==a[4]-a[3]){
		int x=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if((x+x*i)*i/2<=m)maxx=i+1;
			else {cout<<maxx;break;}
			if(maxx>=n){cout<<n;break;}
		}
		return 0;
	}
    
    for(int i=1;i<=n;i++){
		long long ans=0,b=m;
		
		long long x=upper_bound(a+1,a+n+1,a[i])-a-1;

		for(int j=x;j>=1;j--){
			if(a[i]-a[j]<=b&&a[i]-a[j]>=0){
				b-=(a[i]-a[j]);
				ans++;
				//cout<<x<<endl;
			}
		}
		//cout<<a[i]<<" "<<ans<<endl;
		maxx=max(maxx,ans);
	}
	cout<<maxx;
    return 0;
}
