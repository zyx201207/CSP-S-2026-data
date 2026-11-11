#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
bool check1(string str1,string str2){
	string s[9]={"","AB","AC","BA","BC","CA","CB","DF","FD"};
	string str="";
	str+=str1[2];
	str+=str2[2];
	for(int i=0;i<9;i++){
		if(str==s[i]){
			return true;
		}
	}
	return false;
}
bool check2(string str1,string str2){
	string s[9]={"","AB","BA","BC","CB","DF","FD"};
	string str="";
	str+=str1[2];
	str+=str2[2];
	for(int i=0;i<7;i++){
		if(str==s[i]){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(check1(s1,s2)){
				cout<<1;
				if(check2(s1,s2)){
					cout<<1;
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
