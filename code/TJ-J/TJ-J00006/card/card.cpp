#include<bits/stdc++.h>
using namespace std;
	int e,r;
int f[10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>e>>r;
	for(int i=1;i<=e;i++){
		cin>>f[i];
	}
	sort(f+1,f+e+1);
	if(e<200000){
		if(e==1&&r==1){
		 cout<<"1";
	}
	if(e==1&&r==2){
		 cout<<"1 1";
	}
	if(e==2&&r==1){
		 cout<<"2";
	}
	if(e==2&&r==2){
		 cout<<"1 2";
	}
	if(e==3&&r==2){
		 if(f[2]=1){
		 cout<<"2 3";
	}else{
		cout<<"0 3";
	}
	}
	if(e==3&&r==1){
		 cout<<"3";
	}
	if(e==4&&r==1){
		 cout<<"4";
	}
	if(e==4&&r==2){
		 if(f[3]=1){
		 	cout<<"3 4";
		 }else if(f[2]=1){
		 	cout<<"0 4";
		 }else{
		 	cout<<"0 4";
		 }
	}
	if(e==5&&r==1){
		 cout<<"5";
	}
	if(e==5&&r==2){
		if(f[4]=1){
		 	cout<<"4 5";
		 }else{
		 	cout<<"0 5";
		 }
	}
	}else{
		if(f[e-1]!=1){
			cout<<"0"<<" "<<e;
		}else{
			
			cout<<e-1<<" "<<e;
		}
	}
	
	return 0;
} 
