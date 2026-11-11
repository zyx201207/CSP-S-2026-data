#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

bool check(char c1, char c2){
	if ('A'<=c1&&'C'>=c1) return 'A'<=c2&&'C'>=c2;
	return 'D'==c2||'F'==c2;
}

bool check1(char c1, char c2){
	if ('A'<=c1&&'C'>=c1) return abs(c2-c1)==1;
	return true;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1,f2,f3,f4;
	f1 = c1==c2;
	string p1,p2;
	p1 = s1; p2 = s2;
	p1[2] = 'A'; p2[2] = 'A';
	f2 = p1==p2&&f1;
	f3 = check(s1[2],s2[2]) && f2;
	f4 = check1(s1[2],s2[2]) && f3;
	cout<<f1<<f2<<f3<<f4<<endl;
} 
