#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int c,t;
int n,d;
int x[N];
int nt[N];
int cnt;
int ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];			
		}
		for(int i=2;i<=n;i++){
			nt[i]=x[i]-x[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(i-j)>=3){
				if(abs(x[i]-x[j])>=d){
					int l=abs(x[i]-x[j])/d;
					int p=abs(l*d-abs(x[i]-x[j]));
					for(int k=min(i,j)+1;k<=max(i,j);k++){
						if(nt[k]==p){
							cnt++;
						}
					}
					if(cnt==1){
						ans++;
					}
					cnt=0;
				}	
				}
				
			}
		}
		cout<<ans/2<<endl;
		ans=0;
		cnt=0;
		memset(x,0,sizeof(x));
	    memset(nt,0,sizeof(nt));
	}
	
	return 0;
}
