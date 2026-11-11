#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m,sl[100005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>sl[i];
	}
	int maxn=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		
		int aw=sl[i] and sl[j];
	    int l2=aw;
	    
	    for(int j=2;j<m;j++){
	    	if(j+1<n){			
	    	aw=l2 and sl[j+1];
	    	l2=aw;
	}
		if(l2>=maxn){
			maxn=l2;
		}
		
        }    
     }
		
	

	


    
	

}
	cout<<maxn;
}
