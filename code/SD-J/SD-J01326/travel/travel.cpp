#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<string>
#include<cstring>
using namespace std;
string c,c1,s,s1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		cout<<"1";
		if(s[0]==s1[0]&&s[1]==s1[1]){
			cout<<"1";
			if((s[2]>='D'&&s1[2]>='D')||(s[2]<'D'&&s1[2]<'D')){
				cout<<"1";
				if(s[2]==s1[2]+1||s[2]+1==s1[2]){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
