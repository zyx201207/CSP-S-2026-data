#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool flag,flag1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		cin>>c1>>s1>>c2>>s2;
		if(c1 == c2){
			cout<<'1';
		}
		else{
			cout<<'0';
		}
		if((c1 == c2) && (s1[0] == s2[0]) && (s1[1] == s2[1])){
			cout<<'1';
			if(((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || (s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')){
				flag1 = true;
				if((s1[2] == 'A' && s2[2] == 'B')||(s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C'))||(s1[2] == 'C' && s2[2] == 'B')||(s1[2] == 'D' && s2[2] == 'F')||(s1[2] == 'F' && s2[2] == 'D'))
					flag = true;
				}
		}
		else{
			cout<<'0';
		}
		if(flag1)	cout<<'1';
		else	cout<<'0';
		if(flag)	cout<<'1';
		else	cout<<'0';
	return 0;
} 
