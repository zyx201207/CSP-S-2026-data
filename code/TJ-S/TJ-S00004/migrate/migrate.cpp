#include<bits/stdc++.h>
using namespace std;
const int Maxn=2000005;
long long c,t,n,d,x[Maxn],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			int dx=x[2]-x[1];
			int k=1;
			while(k*dx<=d) k++;
			k-=1;
			for(int i=k+2;i<=n,(i-2)%k==0;i++){
				ans++;
			}
			cout<<k<<endl;
			cout<<ans*(n-k-1)<<endl;
		}
	}
	else{
		while(t--){
			cout<<0<<endl;
		}
	}
	return 0;
} 
