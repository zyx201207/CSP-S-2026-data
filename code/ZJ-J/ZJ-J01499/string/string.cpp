#include<bits/stdc++.h>
using namespace std;
struct Node{
	int s;
	char b;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].b;
	}
	int ans=0,t=1,v=n;;
	while(t<v){
		
	
		if(a[t].s>a[v].s){
			for(int i=v;i>t;i--){
				if(a[t].s>a[i].s){
					a[t].s-=a[i].s;
					if(a[i].b!=a[t].b){
						ans+=a[i].s;
					}
				}else{
					
					v=i;
					if(a[v].s==0){
						v--;
					}
					a[i].s-a[t].s;
					a[t].s=0;
					if(a[i].b!=a[t].b){
						ans+=a[t].s;
					}
					
					break;
				}
				
			}
			
		}else{
			for(int i=t;i<v;i++){
				int f=0;
				if(a[v].s>a[i].s){
				
					a[v].s-=a[i].s;
					
					if(a[i].b!=a[v].b){
						ans+=a[i].s;
						
					}
				}else{
					t=i;
					if(a[t].s==0){
						t++;
						
					}
					a[i].s-a[v].s;
					
					a[v].s=0;
					if(a[i].b!=a[v].b){
						ans+=a[v].s;
					}
				
					f=1;
				
				}
				if(f==1){
					
					break;
				}
				
			}
		
		}
	
		
		
	}
		
	
	cout<<ans;
	return 0;		  
}