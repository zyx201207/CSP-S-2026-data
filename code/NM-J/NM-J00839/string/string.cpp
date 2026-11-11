#include<bits/stdc++.h>
using namespace std;
long long n;
struct st{
    long long m;
    char s;
}a[2001000]; 
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
    cin>>n;
    string c;
    for(int i=1;i<=n;i++){
        cin>>a[i].m>>a[i].s;
    }
    for(int i=1;i<=n;i++){
	    for(int j=1;j<=a[i].m;j++){
			c+=a[i].s;
			}
	}
    long long x=0,y=c.size(),ans=0;
    
    
    while(x<y){
		for(int i=0;i<c.size();i++){
		
	        if(c[x]!=c[y]){
			    	ans++;
			    x++,y--;
			  
			}else{
			    x++,y--;
			}
				
	    }
	}
	cout<<ans-1;
    return 0;
}
