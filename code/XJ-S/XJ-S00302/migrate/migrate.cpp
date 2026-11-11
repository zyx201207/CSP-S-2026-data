#include<bits/stdc++.h>

using namespace std;
long long te[100000000000000000],yyy[2000010],xxx[2000010],sp;
long long da=0,ans=0;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.ont","w",stdout);
	
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>xxx[i];
		    if(xxx[i]-xxx[1]>d){
		    	sp=i-1;
		    	break;
			}
		}
	    for(int i=1;i<=n;i++){
	    	yyy[i]=xxx[i]-xxx[sp];
	    	abs(yyy[i]);
	    	te[yyy[i]]++;
	    	da=max(yyy[i],da);
		}
	    for(long long i=1;i<=da;i++){
	    	ans+=yyy[i]/2;
		}
	    cout<<ans;
	    ans=0;
	}
	return 0;
} 
