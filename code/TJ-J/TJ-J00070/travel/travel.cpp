#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	bool t1=true,t2=true,t3=true;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]-'0'!=c2[i]-'0'){
			t1=false;
		}
	}
	if(t1){
		cout<<1;
		for(int i=0;i<2;i++){
			if(s1[i]-'0'!=s2[i]-'0'){
				t2=false;
			}
		}
		if(t2){
			cout<<1;
			if(s1[2]<='C'&&s2[2]<='C'){
				cout<<1;
				
				if((s1[2]-'A'==s2[2]-'A'+1)||(s1[2]-'A'==s2[2]-'A'-1)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if((s1[2]>'C'&&s2[2]>'C')&&(s1[2]<='F'&&s2[2]<='F')){
				cout<<1;
				if((s1[2]-'A'==s2[2]-'A'+2)||(s1[2]-'A'==s2[2]-'A'-2)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				t3=false;
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	return 0;
} 
