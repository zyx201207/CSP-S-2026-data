#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+8;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,h,ans=0,y,o=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>a[i];
		int uun=0;
		if(d>=a[n]-a[1]) {
			cout<<0<<'\n';break;
		}
		for(int i=1;i<n;++i){
			uun+=a[i+1]-a[i];
			if(uun>d) {
				o=i;break;
			}
		}
		for(int q=1;q<=(n-o);++q){
			for(int i=1;i<=n;++i){
			if(a[i]-a[q]>d) {
				    h=i;break;
			    }
		    }
		    for(int i=h;i<=n;++i){
			    int cnt=0;
		        for(int j=1;j<=i;++j){
		    	    if(a[j]-a[q]<=d && a[i]-a[j]<=d) cnt++;	
			        }
			    if(cnt==2) ans++;
		    }
		}
		
		cout<<ans<<'\n'; 
	}
	fclose(stdin);
	fclose(stdout);
return 0;
} 

