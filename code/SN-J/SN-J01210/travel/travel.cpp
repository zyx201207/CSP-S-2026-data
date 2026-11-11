#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	int sum=0;
	cin>>c1>>s1>>c2>>s2;
	
	for(int i=0;i<=1;i++){//检测同一车厢 
		if(c1[i]==c2[i]){
			sum++;
		}
	}
	if(sum==2){
		cout<<1;
		
		sum = 0;	//同一列
		for(int i=0;i<=1;i++){
			if(s1[i]==s2[i]){
				sum++;
			}
		}      
		if(sum==2){
			cout<<1;
			
			sum=0;//同一侧
			if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'||s1[2]<='E'&&s1[2]>='D'&&s2[2]<='E'&&s2[2]>='D1'){
			
				cout<<1;
				
				sum=0;//相邻
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					sum++;
				}
				if(sum==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<00;
			}
		}
		else{
			cout<<000;
		}	
	}
	else{
		cout<<0000;
	}	
	
	return 0;
}
