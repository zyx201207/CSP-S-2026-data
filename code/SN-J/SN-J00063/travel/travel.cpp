#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int x=3,y=4;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				x=1;
			}if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				y=1;
			}if(s1[2]=='D'||s1[2]=='F'){
				x=2;
			}if(s2[2]=='D'||s2[2]=='F'){
				y=2;
			}
			if(x==y){
				cout<<1;
				int a=abs(int(s1[2])-int(s2[2]));
				if(a==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
		cout<<0<<0<<0;
		return 0;
		}
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
} 
