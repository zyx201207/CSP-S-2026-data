#include <bits/stdc++.h>
using namespace std;
string car1,car2,s1,s2;
int main(){
	freopen("travel1.in*","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>car1>>s1>>car2>>s2;
	if(car1==car2){
		cout<<1;
		if(s1[1]==s2[1])cout<<1;//同一排
		else cout<<0;
		if(('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C')){
			cout<<1;
			if(char(s1[1]-1)+s1[2]==s2[1]+s2[2]||char(s1[1]+1)+s1[2]==s2[1]+s2[2]){
				cout<<1;
				return 0;
			}
			else if(s1[1]+char(s1[2]-1)==s2[1]+s2[2]||s1[1]+char(s1[2]+1)==s2[1]+s2[2]){
				cout<<1;
				return 0;
			}
			else cout<<0;
		}
		else if(('D'<=s1[2]&&s1[2]<='F')&&('D'<=s2[2]&&s2[2]<='F')){
			cout<<1;
			if(char(s1[1]-1)+s1[2]==s2[1]+s2[2]||char(s1[1]+1)+s1[2]==s2[1]+s2[2]){
				cout<<1;
				return 0;
			}
			else if(s1[1]+char(s1[2]-2)==s2[1]+s2[2]||s1[1]+char(s1[2]+2)==s2[1]+s2[2]){
				cout<<1;
				return 0;
			}
			else cout<<0;
		}
		else cout<<"00";
	}
	else cout<<"0000";
	
	return 0;
}