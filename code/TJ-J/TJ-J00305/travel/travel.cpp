#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	char train_r[2];
	char train_x[2];
	
	char sit_r[3];
	char sit_x[3];
	
	for(int i=0;i<2;i++){
		cin>>train_r[i];
	}
	for(int i=0;i<3;i++){
		cin>>sit_r[i]; 
	}
	
	for(int i=0;i<2;i++){
		cin>>train_x[i];
	}
	for(int i=0;i<3;i++){
		cin>>sit_x[i]; 
	}
	
	int ans[4]={1,1,1,1};
	
	for(int i=0;i<2;i++){
		if(train_r[i] != train_x[i]){
			ans[0]=0;
			ans[1]=0;
			ans[2]=0;
			ans[3]=0;
			
			for(int i=0;i<4;i++){
				cout<<ans[i];
			}
			
			return 0;
		}
	}
	
	for(int i=0;i<2;i++){
		if(sit_r[i] != sit_x[i]){
			ans[1]=0;
			ans[2]=0;
			ans[3]=0;
			
			for(int i=0;i<4;i++){
				cout<<ans[i];
			}
			
			return 0;
		}
	}
	
	int r_sit=0;
	int x_sit=0;
	
	if('A'<=sit_r[2] && sit_r[2]<='C'){
		r_sit=1;
	}else{
		r_sit=2;
	}
	
	if('A'<=sit_x[2] && sit_x[2]<='C'){
		x_sit=1;
	}else{
		x_sit=2;
	}
	
	if(r_sit != x_sit){
		ans[2]=0;
		ans[3]=0;
		
		for(int i=0;i<4;i++){
			cout<<ans[i];
		}
			
		return 0;
	}else if(r_sit == 1){
		if(sit_r[2]!='B' && sit_x[2]!='B'){
			ans[3]=0;
		}
	}
	
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	
	return 0;
}
