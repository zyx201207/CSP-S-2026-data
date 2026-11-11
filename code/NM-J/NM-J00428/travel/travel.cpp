#include <bits/stdc++.h>
using namespace std;
string che(int a,int b,string sa,string sb){
	string s = "0000";
	if(a!=b){
		return s;
	}
	s[0] = '1';
	
	int pa = (sa[0]-'0')*10+(sa[1]-'0');
	int pb = (sb[0]-'0')*10+(sb[1]-'0');
	if(pa != pb){
		return s;;
	}
	s[1] = '1';
	
	int zuowei[11] = {0,1,1,1,2,2};
	int ca = sa[2]-'A'+1;
	int cb = sb[2]-'A'+1;
	if(ca == 6){
		ca--;
	}
	if(cb == 6){
		cb--;
	}
	if(zuowei[ca] != zuowei[cb]){
		return s;
	}
	s[2] = '1';
	
	if(ca-1 != cb && ca+1 != cb){
		return s;
	}
	s[3] = '1';
	return s;
}
int main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a = 0,b = 0;
	string sa;
	string sb;
	scanf("%i",&a);
	cin>>sa;
	scanf("%i",&b);
	cin>>sb;
	string s1 = che(a,b,sa,sb);
	cout<<s1;

	return 0;
}
