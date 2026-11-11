#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s2[0] == s1[0] and s2[1] == s1[1]){
		cout<<1;
		if(s1[2] == 'D' or s1[2] == 'F'){
			if(s2[2] == 'D' or s2[2] =='F'){
				cout<<11;
				return 0;
			}else{
				cout<<"00";
				return 0;
			}
		}else if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C'){
			if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'){
				cout<<1;
				if(s1[2]=='A'){
					if(s2[2]=='B'){
						cout<<1;
						return 0;
					}else{
						cout<<0;
						return 0;
					}
				}
				if(s1[2]=='B'){
					if(s2[2]=='A' or s2[2]=='C'){
						cout<<1;
						return 0;
					}else{
						cout<<0;
						return 0;
					}
				}
				if(s1[2]=='C'){
					if(s2[2]=='B'){
						cout<<1;
						return 0;
					}else{
						cout<<0;
						return 0;
					}
				}
				cout<<0;
				return 0;
			}else{
				cout<<"00";
			}
		}
	}else{
		cout<<"000";
	}
	return 0;
}
