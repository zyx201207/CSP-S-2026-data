#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,x,ans;
int f,f1,xi,yi;
long long d;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int k=1;k<=n;k++){
			f=0;
			for(int i=k;i<=n;i++){
				if((a[i]-a[i-1])>d){
					f=1;
					break;
				}
				if(a[i]>(a[k]+d)){
					xi=i-1;
					break;
				}
			}
			for(int i=xi;i<=n;i++){
				if((a[i]-a[i-1])>d){
					f=1;
					break;
				}
//				if(a[i]=(a[k]+2*d)){
//					yi=i;
//					cout<<"IOIO ";
//					break;
//				}
				else if(a[i]>=(a[k]+2*d)){
					yi=i;
					break;
				}
			}
			if(f==0){
				if(yi==0){
					yi=n+1;
				}
				if(xi==0){
					xi=n;
				}
				ans+=(yi-xi-1);
//				cout<<xi<<" "<<yi<<"\n";
				xi=0,yi=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
