#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=1;i<=18;i++){
			
		if(i==s1.size()>>1&&i==s2.size()>>1){
			cout<<1;
		}else{
			cout<<0;
		}
		break;	
	}
	if(s1.size()>>2-'A'>=3&&s2.size()>>2-'A'>=3){
		cout<<0;
	}else{
		cout<<1;
	}
	for(int j='A';j<='E';j++){
		if(j==s1.size()>>2&&j==s2.size()>>2-'A'==1){
			cout<<0;
		}else{
			cout<<1;
			
		}
		break;
	}
	
	
	
	return 0;
	
}
