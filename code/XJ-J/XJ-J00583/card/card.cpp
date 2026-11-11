#include<bits/stdc++.h>
using namespace std;

    int n,m,a[100000],b[100000],c[100000],d[100000],e=0,s1=0,s2=0,s3=0,w=0;

main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	b[i]=a[i];
    	
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		   c[j]=b[j];
	}
		e=b[i];
		
		while(1){
		w=0;	
		for(int j=0;j<n;j++){
		if(c[j]==e){
				for(int z=j;z<i;z++){
	            c[j]=0;
	}
	
		}
	}
	
	for(int j=0;j<n;j++){
		for(int z=0;z<n;z++){
	       if(c[z]==c[j]&&c[z]!=0 ){
	       	   e=c[z];
		   } 
		   else{
		   	w++;
		   }    
	}
	
		}
		if(w==n*n){
			break;
		}
		cout<<w;
	}
		for(int j=0;j<n;j++){
		   if(c[j]==1){
		   	s1++;
		   }
		   if(c[j]==2){
		   	s2++;
		   }
		   if(c[j]==3){
		   	s3++;
		   }
		}
	
	
	}
	cout<<s1<<" "<<s2<<" "<<s3;
    
}

