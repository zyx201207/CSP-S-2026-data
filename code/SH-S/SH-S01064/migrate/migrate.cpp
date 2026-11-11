#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int c,t,n;
long long a[MAXN],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(a,0,sizeof(a));
		long long k=0;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2) k=a[2]-a[1];
			else if(i>2)
				if(a[i]-a[i-1]!=k) flag=false;
		}
		long long ans=0;
		if(n>3){
			if(flag){
				if(d>=2*k){
					if(n%2==0) ans=(n-2)/2*(n-3);
					else ans=(n-3)/2*(n-2);
				}
			}
			else ans=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
