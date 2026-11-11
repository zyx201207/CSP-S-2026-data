#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in ","r",stdin);
	//freopen("crystal.out ","out",stdout);
	int n,m,a[500],q[500];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int w=n/2+1;
	    
	for(int i=1;i<=n;i++){
	    for(int o=1;o<=n;o++){
	    
		    for(int j=m;j>=1;j--){
		    	a[i]+=1;
			 
			      
		                    if(a[i]==a[w]){
		       	                q[o]=q[o]+1;
		       	                break;
			                }
			               
			            
			    	    
	        }
			break;
	           
    	}
	}

	

	
	for(int i=1;i<=n;i++){
		if(q[i]<n&&q[i]>0) cout<<q[i]<<endl;
		
		
	}

	
	return 0;
}

