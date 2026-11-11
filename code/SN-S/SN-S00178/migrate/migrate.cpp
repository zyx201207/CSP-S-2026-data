#include<bits/stdc++.h>
using namespace std;
long long a[60000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n;
		long long d;
	    cin>>n>>d;
	    for(long long i=1;i<=n;i++){
		    cin>>a[i];
	    }
	    if(n<=3){
	    	cout<<0;
	    	return 0;
		}
	    long long y=a[2]-a[1];
	    long long f=d/y;
	    cout<<f; 
	    if(f<=1||f*2>n){
	        cout<<0;	
	        break;
	    }
	    cout<<n-f*2+1<<endl;
    }	
	return 0;
}
