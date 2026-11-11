#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
char a,b;
int a1,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=s1[2];
	b=s2[2];
	a1=a-'0';
	bb=b-'0';
	if(c1==c2) {
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<'1';
			if((a<='C'&&a>='A'&&b<='C'&&b>='A')||(a<='F'&&a>='D'&&b<='F'&&b>='D')){
				cout<<'1';
				if(abs(a1-bb)==1){
					cout<<'1';
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
