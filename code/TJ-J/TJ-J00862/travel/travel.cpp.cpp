#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<1;
			if(s1[2]-64<4&&s2[2]-64<4 || s1[2]-64>=4&&s2[2]-64>=4){
				cout<<1;
				if(s1[2]-64==s2[2]-65||s1[2]-64==s2[2]-63){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
