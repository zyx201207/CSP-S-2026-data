#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0,a[1110]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	for(int i=1;i<=n-1;i++){		
		for(int j=i+1;j<=n;j++){			
			int l=a[i]&a[j];							
			if(l>max){				
				max=l;
		
		    }
	    }
    }  
	cout<<max;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
