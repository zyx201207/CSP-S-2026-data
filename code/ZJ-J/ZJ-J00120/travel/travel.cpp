#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if((c1[0]-'0')!=(c2[0]-'0')||(c1[1]-'0')!=(c2[1]-'0')){
		cout<<"0000";
	}else{
		if(((s1[0]-'0')!=(s2[0]-'0'))||((s1[1]-'0')!=(s2[1]-'0'))){
			cout<<"1000";
		}else{
			bool a=(s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&&s2[2]>='A');
			bool b=(s1[2]<='F'&&s1[2]>='D')&&(s2[2]<='F'&&s2[2]>='D');
			if(a){
				if(abs(s1[2]-s2[2])==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else if(b){
				cout<<"1111";
			}else{
				cout<<"1100";
			}
		}
	}
	return 0;
}
