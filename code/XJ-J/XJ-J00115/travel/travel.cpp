#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[5],s1[5],c2[5],s2[5];
	for(int i=0;i<=1;i++){
		cin>>c1[i];
	}
	for(int i=0;i<=2;i++){
		cin>>s1[i];
	}
	for(int i=0;i<=1;i++){
		cin>>c2[i];
	}
	for(int i=0;i<=2;i++){
		cin>>s2[i];
	}
	
	int z=0;
	
	for(int i=0;i<=1;i++){
		if(c1[i]==c2[i]){
			z++;
		}
		
		 
	}
	if(z==2)cout<<1;
	if(z!=2)cout<<0;
		
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i]){
			z++;
		}
	
	
	}
	if(z==4)cout<<1;
	if(z!=4)cout<<0;  
	cout<<0;
	cout<<0;


	
	


	
	
	return 0; 
}

