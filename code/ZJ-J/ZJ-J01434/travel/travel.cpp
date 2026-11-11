#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string ans="";
	if(a!=c){
		ans="0000";
		cout<<ans<<endl;
		return 0;
	}else{
		ans+='1';
		
		if(b[0]==d[0]&&b[1]==d[1]){
			
			if(b[2]-'A'<=2 &&d[2]-'A'<=2){
				if((b[2]-'A'==2 &&d[2]-'A'==0)||(b[2]-'A'==0 &&d[2]-'A'==2)){
					cout<<"1110"<<endl;
					return 0;
				}else{
					cout<<"1111"<<endl;
					return 0;
				}
			}else if(b[2]-'A'>2 &&d[2]-'A'>2){
				cout<<"1111"<<endl;
				return 0;
			}else{
				cout<<"1100"<<endl;
				return 0;
			}
			
		}else{
			cout<<"1000"<<endl;
			return 0;
		}
	}
}
