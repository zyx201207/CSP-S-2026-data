#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
int a[200100];
char c[200100];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
	}
	if(n<=2){
		if(n<=1){
			cout<<0;
			return 0;
		}
		else{
			if(a[1]==a[2]){
				if(c[1]==c[2]){
					cout<<0;
					return 0;
				}
				else{
					cout<<a[1];
					return 0;
				}   
			}
			else if(a[1]>a[2]){
				    if(c[1]==c[2]){
				    	cout<<0;
				    	return 0;
					}
					else{
						cout<<a[2];
					}
					
			     }
			     else{
			     	
				  if(c[1]==c[2]){
			     	cout<<0;
				  }
				  else{
				  	cout<<a[1];
				  	return 0;
				  }
				    
			    }
		}
	}
	else{
	  int t=n;
	  int k1=1,k2=1;
	  char s1=c[1],s2=c[n];
	  for(int i=2;i<=n/2;i++){
	  	  if(c[i]==s1){
	  	  	  k1++;
			}
	  }
	  for(int i=n-1;i>=n/2;i--){
	  	  if(c[i]==s2){
	  	  	 k2++;
			}
	  }
	  if(k1==k2&&k1+k2==n){
	  	 cout<<ans/2;
	  	 return 0;
	  }
	  cout<<0;
	}
	return 0;
} 
