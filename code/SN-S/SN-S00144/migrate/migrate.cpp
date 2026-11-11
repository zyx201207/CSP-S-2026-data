#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+10; 
ll c,t,n,d,csp;
ll a[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		csp=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				ll lj=0;
				for(int k=i;k<=j;k++){
					if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
						lj++;
					}
				}
				if(lj==2) csp++;
			}
		}	
		cout<<csp<<"\n";
	}
	
	return 0;
}
