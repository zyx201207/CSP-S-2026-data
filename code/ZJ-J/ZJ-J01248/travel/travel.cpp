#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
bool check(char a,char b){
	return (a=='A'||a=='B'||a=='C')==(b=='A'||b=='B'||b=='C');
}
bool near(char a,char b){
	return check(a,b)&&(a=='D'||a=='F'||a=='B'||b=='D'||b=='F'||b=='B');
}
int main(){
	freopen("travel.in","r+",stdin);
	freopen("travel.out","w+",stdout);
	cin>>s1>>s2>>t1>>t2;
	cout<<(s1==t1?(s2.substr(0,2)==t2.substr(0,2)?(check(s2[2],t2[2])?(near(s2[2],t2[2])?"1111":"1110"):"1100"):"1000"):"0000");
} 
