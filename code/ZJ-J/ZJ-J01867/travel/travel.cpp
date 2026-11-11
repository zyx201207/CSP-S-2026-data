#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long
int seat(char x){
	switch(x){
		case 'A':return 1;
		case 'B':return 2;
		case 'C':return 3;
		case 'D':return 5;
		case 'F':return 6;
	}
	exit(-1);
}
inline int side(char a,char b){
	return ((seat(a)<4)&&(seat(b)<4))||((seat(a)>4)&&(seat(b)>4));
}
signed main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char x1,x2;
	bool r1,r2,r3,r4;
	cin>>c1>>s1>>x1>>c2>>s2>>x2;
	r1=(c1==c2),r2=(r1&&(s1==s2)),r3=(r2&&(side(x1,x2))),r4=(r3&&(abs((seat(x1)-seat(x2)))==1));
	cout<<r1<<r2<<r3<<r4;
	return 0;
}