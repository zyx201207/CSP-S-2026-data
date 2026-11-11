#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		cout<<'1';
		if(s[0]==s1[0] && s[1]==s1[1]){
			cout<<1;
			if(s[2]>='D' && s[2]<='F' && s1[2]>='D' && s1[2]<='F' || s[2]>='A' && s[2]<='C' && s1[2]>='A' && s1[2]<='C'){
				cout<<'1';
				if(s[2]>='D' && s[2]<='F' && s1[2]>='D' && s1[2]<='F'){
					cout<<'1';
					return 0;
				}
				else if(s[2]>='A' && s[2]<='C' && s1[2]>='A' && s1[2]<='C'){
					if(s[2]-s1[2]==1 || s1[2]-s[2]==1){
						cout<<'1';
					}else{
						cout<<'0';
						return 0;
					}
				}
				else{
					cout<<'0';
					return 0;
				}
			}
			else{
				cout<<'0'<<'0';
				return 0;
			}
		}
		else{
			cout<<'0'<<'0'<<'0';
			return 0;
		}
	}
	else{
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	}
	return 0;
}
