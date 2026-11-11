#include<bits/stdc++.h>
using namespace std;
bool dec(char a){
	if(a=='A'||a=='B'||a=='C'){
		return 1;
	
	}else{
		return 0;
		}



}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
		if(dec(s1[2])==dec(s2[2])){
		cout<<1;
			if(abs(int(s1[2]-s2[2]))==1){
			cout<<1;
			}else{			
			cout<<0;
			}
		}else{
		    cout<<"00";
		}
		
		}else{
			cout<<"000";
		
		}
	
	
	}else{
      cout<<"0000";	
	}
	
    
	return 0;
}
