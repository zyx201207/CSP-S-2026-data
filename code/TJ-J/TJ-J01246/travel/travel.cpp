#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;	
	int sum = 0;
	int um = 0;
	for(int i = 0;i<2;i++){
		if(c1[i]==c2[i]){
			sum++;
		}if(s1[i]==s2[i]){
			um++;
		}
	}
	if(sum==2){
		cout<<1;
		
	}
	else{
		cout<<0;
	}
	if(um==2&&sum==2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[2]<='C'&&s2[2]<='C'&&s2[2]!=c2[2]&&sum==2&&um==2){
		cout<<1;
	}
	else if(s1[2]>='D'&&s2[2]>='D'&&s2[2]!=c2[2]&&sum==2&&um==2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[2]==s2[2]+1&&sum==2&&um==2&&s1[2]<='C'&&s2[2]<='C'){
		cout<<1;
	}
	else if (s1[2]==s2[2]-1&&sum==2&&um==2&&s1[2]<='C'&&s2[2]<='C'){
		cout<<1;
	}else if (s1[2]==s2[2]+1&&sum==2&&um==2&&s1[2]>='D'&&s2[2]>='D'){
		cout<<1;
	}else if (s1[2]==s2[2]-1&&sum==2&&um==2&&s1[2]>='D'&&s2[2]>='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
