#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if('A'<=s1[2]&&'C'>=s1[2]&&'A'<=s2[2]&&'C'>=s2[2]){
			cout<<1;
		}
		else if('D'<=s1[2]&&'F'>=s1[2]&&'D'<=s2[2]&&'F'>=s2[2]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if('A'<=s1[2]&&'C'>=s1[2]&&'A'<=s2[2]&&'C'>=s2[2]){
			if(abs((s2[2]-'0')-(s1[2]-'0'))==1){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if('D'<=s1[2]&&'F'>=s1[2]&&'D'<=s2[2]&&'F'>=s2[2]){
			if(abs((s2[2]-'0')-(s1[2]-'0'))==2){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 
