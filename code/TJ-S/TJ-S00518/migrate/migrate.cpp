#include<iostream>
#include<cstdio>
using namespace std;
long long c,t,n,d,a[2000005],s;						
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){						
    	cin>>n>>d;					
    	for(int j=1;j<=n;j++){					
    		cin>>a[i];				
		}				
		for(int j=1;j<=n-3;j++){				
			for(int y=i+3;y<=n;y++){			
				if(a[y]-a[i]<=d){		
					if(y-i==3){	
						s++;
					}	
				}		
			}			
		}	
		cout<<s<<endl;
		s=0;	
	}							
	return 0;					
}
