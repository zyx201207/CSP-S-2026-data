#include<bits/stdc++.h>
//sn-J01113 余俊辰 西安市曲江第一学校 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
 	int c1,c2;
 	string s1,s2;
	 cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])
		cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	int n1,n2;
	n1=s1[2]-'A',n2=s2[2]-'A';
	if(n1<=2 && n2<=2)cout<<"1";
	else {
		if(n1>2 && n2>2)cout<<"1";
		else{
			 cout<<"00";
			 return 0;
		}
	}
	 
	if(abs(n1-n2)<=1)cout<<"1";
	else cout<<"0";
	return 0;
}
// 02 01A 02 01B 
