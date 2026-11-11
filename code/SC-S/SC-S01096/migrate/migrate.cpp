#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],s[2000005],x,ji[2000005];

void clear(){
	memset(a,0,2000005);
	memset(s,0,2000005);
	memset(ji,0,2000005);
}
int main(){
	freopen("migrate.in","r",stdin);
	cin>>c>>t;
	while(t--){
		cin>>n>>d>>a[0];
		s[0]=a[0];
		for(int i=1;i<n;i++){
			cin>>a[i];
			
			s[i]+=a[i];
		}
		int pd=0;
		for(int i=2;i<n-1;i++){
			if(a[i-1]-a[i-2]!=a[i+1]-a[i]){
				pd=1;
				i=n+1;
			}
		}
		if(a[n-1]-a[0]+1<d*2){
			cout<<0<<endl;
		}else if(pd==1){
			for(int i=1;i<=n;i++){
			    for(int j=i+1;j<=n;j++){
				    int cu=s[j]-s[i],cu1=s[j]-s[i-1];
				    if(cu<=d && cu1-cu<d*2 && cu1-cu>=d){
				    	if(cu1-cu>d+2){
				    		x--;
				    		i++;
						}else if(ji[i]==0){
								x++;
								ji[i]=1;
						}
					}else{
				    	i++;
					}
			    }
		    }
		    cout<<x<<endl;
		}else{
			int gl=0;
			for(int i=d*2;i<n+1;i+=d){
		        gl+=n-i+1;
		    }
		    cout<<gl<<endl;
		}
		
		clear();
	}
	
	
	freopen("migrate.out","w",stdout);
	return 0;
} 