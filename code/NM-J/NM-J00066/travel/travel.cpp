#include<bits/stdc++.h>
using namespace std;



main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,i;
	char s1[10],s2[10];
	
	cin>>c1;
	for(i=0;i<=2;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(i=0;i<=2;i++){
		cin>>s2[i];
	}
	int q,w;
	q=s1[0]+s1[1];
	w=s2[0]+s2[1];
	int z=s1[2];
	int x=s2[2];
	if(c1==c2){
		cout<<"1";
		if(q==w){
			cout<<"1";
			if(z+x==131){
				cout<<"11";
			}
			if(z+x==133){
				cout<<"11";
			}
			if(z+x==138){
				cout<<"11";
			}
			if(z+x==132){
				cout<<"10";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
			return 0;
		}
		
		
	}
	if(c1<c2||c1>c2){
		cout<<"0000";
		return 0;
	}
	
	return 0;
} 
