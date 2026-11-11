#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int mx=2e6+10;
ll c,t,a[mx];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1,j=1;i<=n,j<=n;i++){
			if(j==n&&a[j]-a[i]<d+1) break;
			while(a[j]-a[i]<2*d-1&&j<n) j++;
			ans+=j-i-d;	
		} 	
		cout<<ans<<endl;
	}
	return 0;
} 