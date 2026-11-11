#include<bits/stdc++.h>
using namespace std;

    int a,b[100000]={1},s=0,s1=0;
    char c[100000001],d[100000001],e[100000001],f[100000001];

main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
    cin>>a;
    for(int i=1;i<=a;i++){
    	cin>>b[i];
		cin>>c[i];
    	s=s+b[i];
    	for(int j=s1;j<s;j++){
    		d[j]=c[i];
    		
    	}
    	s1=s1+b[i];
	}
	
	s1=0;
	for(int j=s-1;j>=0;j--){
		
		for(int i=s1;i<=s1;i++){
		
    		e[i]=d[j];
    		
    	}
    	s1++;
    	}
	
	s1=0;
	
	
	
	if(s%2!=0){
		
		for(int i=0;i<s/2;i++){
			f[i]=d[i];
			
		}
		
		for(int i=s/2+1;i<s;i++){
		
			for(int j=s1;j<=s1;j++){
		d[i]=f[j];	
    	
    	}
    	s1++;
		}
		
	}
	else{
		for(int i=0;i<s/2;i++){
			f[i]=d[i];
		}
		for(int i=s/2;i<s;i++){
			
			for(int j=s1;j<=s1;j++){
		d[i]=f[j];
    	s1++;
    	}
			
		}
	}
	
	
    	s1=0;
    for(int j=0;j<=s;j++){
    	if(d[j]!=e[j]){
    		s1++;
		}
		
    	}
		cout<<s1;	
}

