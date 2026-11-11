#include<bits/stdc++.h>
using namespace std;
string s[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b,c,d;
	string s1,s2;
	cin>>a>>s1>>c>>s2;
	if(a==c){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
				cout<<"1";
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
					cout<<"1";
				}
				else cout<<"0";
			}
//			if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
//				cout<<"1";
//				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
//					cout<<"1";
//				}
//				else cout<<"0";
//			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
