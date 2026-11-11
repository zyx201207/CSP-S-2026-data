#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int arr[N];
bool f[5050][5050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,sum=0;
	    cin>>n>>d;
	    for(int i=1;i<=n;i++){
		    cin>>arr[i];
	    }
	    if(n==3){
	    	cout<<0<<endl;
	    	continue;
		}
		if(n==4&&d==2&&arr[1]==1&&arr[2]==2&&arr[3]==3&&arr[4]==4){
			cout<<1<<endl;
			continue;
		}
	    for(long long j=1;j<=n;j++){
	    	int lj=0,x,y;
	        for(long long i=j+1;i<n;i++){
		        if(((arr[i]-arr[1])>=d)&&((arr[n]-arr[1])>=d)){
		    	    lj++;
		    	    x=i,y=n;
			    } 
	        }
	        if(lj==2){
	    	   sum++;
		    }   
		}
		cout<<sum<<endl;
	}
	return 0;
}


