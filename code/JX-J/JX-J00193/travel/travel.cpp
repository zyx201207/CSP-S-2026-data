#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c,s,c1,s1,ans="";
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		if(s[0]+s[1]==s1[0]+s1[1]){
			int a=s[2]-'A',a1=s1[2]-'A';
			if((a<=2&&a1<=2)||(a>2&&a1>2)){
				if(abs(a-a1)==1){
					cout<<"1111"<<endl;
				}
				else cout<<"1110"<<endl;
			}
			else cout<<"1100"<<endl;
		}
		else cout<<"1000"<<endl;
	}
	else cout<<"0000"<<endl;
	return 0;
}
