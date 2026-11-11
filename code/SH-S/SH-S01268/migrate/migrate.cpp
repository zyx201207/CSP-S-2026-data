#include <bits/stdc++.h>
using namespace std;
#define int long long
struct isl{
	int bs;
	int kn; 
};
int c,t;
int x[2000010]={};
isl dt[2000010]={};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		int ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)cin>>x[j];
		for(int j=1;j<=n;j++){//Æðµã
	        for(int k=1;k<=n;k++){
	     	dt[k].bs=99999999;
		    	dt[k].kn=0;
	    	}
	    	dt[j].bs=0;
	    	dt[j].kn=1;
	    	for(int k=j;k<=n;k++){
		    	for(int z=k+1;z<=n;z++){
		    	    if(x[z]-x[k]>d)break;
	    	    	if(dt[z].bs>dt[k].bs+1){
	            		dt[z].bs=dt[k].bs+1;
		        		dt[z].kn=dt[k].kn;
		        	}
		        	else if(dt[z].bs==dt[k].bs+1){
		        		dt[z].kn+=dt[k].kn;
		        	}
		        }
		        if(dt[k].kn==2)ans++;
		    }
	    }
	    cout<<ans<<endl;
	} 
	return 0;
}
