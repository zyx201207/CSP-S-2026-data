#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e6+5;
int c,t,n,d,x[M],h[M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			h[i]=x[i]-x[i-1];
			if(h[i]<0){
				h[i]-=2*h[i];
			}
			if(h[i]>d){
			    cout<<"0"<<'\n';
		    }
		}
	}
	return 0;
} 
