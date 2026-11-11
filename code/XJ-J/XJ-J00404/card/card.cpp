#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long cards[n+5];
    long long card[n+5];
	long long ans[m+5];
    long long id=0;
    long long sum[m+5];
	for(long long i=0;i<n;i++){
		cin>>cards[i];
	}
	for(int t=0;t<n;t++){
	    id=0;
	    for(int i=0;i<m;i++){
	        ans[i]=0; 
	    	sum[i]=0;  
	    }
    	
	
    	for(long long i=0;i<n;i++){
    		if(ans[cards[i]]==0){
    		    card[id]=cards[i];
    		    ans[cards[id]]++;
    		    id++;
    	    }
        	else{
    			for(long long j=id;j>=0;j--){
    				id-=1;
			    	if(ans[cards[i]]==1){
		    		    id++;
		    		    break;
		    		}
		    		ans[id]==0;
		    		card[id]==0;
	    	    }
	    	}    
        }
    
        for(long long i=0;i<id;i++){
	    	sum[i]++;
    	}
    }
	for(long long i=0;i<m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}