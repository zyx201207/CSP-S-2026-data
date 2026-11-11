#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;

int n,a[N],ans=1,s[N];
unsigned long long m; 

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+ans;j<=n;j++){
			int cost=s[j]-s[i-1]-a[j]*(j-i+1);
//			cout<<cost<<" "<<m<<" "<<i<<" "<<j<<endl;
			if(-cost<=m){
				ans=max(ans,j-i+1);
			}
			else{
				j=n+1;
			}
		}
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}
