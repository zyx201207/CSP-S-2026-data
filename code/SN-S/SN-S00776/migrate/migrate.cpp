#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long c,t,n,d,a[maxn],k[maxn];
bool flag=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	if(1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1){
				k[i]=a[i]-a[i-1];
			}
		}
		for(int i=2;i<=n-1;i++){
			if(k[i]!=k[i+1]) flag=0;
		}
		if(flag){
			if(d<=k[2]){
				while(t--){
					cout<<1;
				}
				return 0;
			}
		}	
	}
	if(1){
		while(t--){
			cout<<0<<"\n";
		}		
	}	
	return 0;
}
