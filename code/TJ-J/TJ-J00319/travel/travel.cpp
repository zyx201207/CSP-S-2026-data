#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1="",s2="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	while(1){
		if(c1==c2){
			cout<<'1';
		    if(s1[1]==s2[1]){
		    	cout<<'1';
		    	if(s1[2]==s2[2]){
		    		cout<<'1';
		    		if(s1[3]==s2[3]){
		    			cout<<'1';
		    			break;
					}else{
						cout<<'0';
						break;
					}
				}else{
					cout<<'00';
					break;
				}
			}else{
				cout<<'000';
				break;
			}
		}else{
			cout<<'0000';
			break;
		}
	}
	return 0;
}
