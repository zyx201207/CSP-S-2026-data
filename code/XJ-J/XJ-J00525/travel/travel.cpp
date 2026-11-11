#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	int seat1=0,seat2=0;
	for(int i=0;i<2;i++){
		seat1*=10;
		seat1+=s1[i]-'0';
		
	//	cout<<s1[i]<<" ";
		seat2*=10;
		seat2+=s2[i]-'0';
		
		//cout<<s2[i]<<endl;
	}
	
	if(seat1!=seat2){
		cout<<1<<0<<0<<0;    
		return 0;
	}
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))==false){
		cout<<1<<1<<0<<0;
		return 0;
	}
	int o=s1[2]-s2[2];
	if(abs(o)>1){
		cout<<1<<1<<1<<0;
		return 0;
	}
	cout<<1<<1<<1<<1;
	return 0;
}