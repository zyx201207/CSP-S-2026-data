#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2,s3,s4;
ll flag;
bool check(char x,char y){
	if(x>y)swap(x,y);
	if(x=='D'&&y=='F')return true;
	if(x=='B'&&y=='C')return true;
	if(x=='A'&&y=='B')return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	flag=1;
	flag&=(s1==s3);
	cout<<flag;
	flag&=(s2.substr(0,2)==s4.substr(0,2));
	cout<<flag;
	flag&=(!((s2[2]<='C')^(s4[2]<='C')));
	cout<<flag;
	flag&=check(s2[2],s4[2]);
	cout<<flag;
	return 0;
}
