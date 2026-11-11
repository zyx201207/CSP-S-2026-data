#include<bits/stdc++.h>
using namespace std;
const int N=2e6+510;
long long a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,k,p=0,ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
			p=0;
			int x,y=i+2,l;
				for(;y<j;) {
					l=y;
					x=upper_bound(a+1,a+n+1,a[l-1]+k)-a-1,y=upper_bound(a+1,a+n+1,a[l]+k)-a-1;
					if(a[l]-a[l-2]<=k&&x==y) p++;}
			if(p==1) ans++;}
		cout<<ans<<"\n";}
}
