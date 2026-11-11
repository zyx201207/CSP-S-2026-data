#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,ans;
int x[1000010],dis[1000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=0,d=0;
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
		    cin>>x[i];
		    dis[i]=x[i]-x[i-1];
	    }
	    dis[1]=0;
	    for(int i=1;i<n-1;i++){
		    for(int j=i+2;j<=n;j++){
		    	ll f=x[j]-x[i];
		    	if(j-i<=3)continue;
		    	if(dis[i]%2!=0)ans++
	        }
	    }
	    
	    cout<<ans-1<<endl;
}
    return 0;
	}
	
