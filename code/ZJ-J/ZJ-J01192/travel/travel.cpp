#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x=(s1[0]-'0')*10+(s1[1]-'0');
	int y=(s2[0]-'0')*10+(s2[1]-'0');
	int a=(s1[2]-'A'),b=(s2[2]-'A');
	if(c1==c2){
		if(x==y){
			if(a<=2&&b<=2){
				if((a-b)==1||(b-a)==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else if(a>2&&b>2){
				cout<<"1111";
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
