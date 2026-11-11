#include<iostream>
using namespace std;
long long s,z;
long long a1,a2,a3,a4,a5,a6,a7,a8,a9;
long long b1,b2,b3,b4,b5,b6,b7,b8,b9;
long long c1,c2,c3,c4,c5,c6,c7,c8,c9;
long long d1,d2,d3,d4,d5,d6,d7,d8,d9;
int main(){
	int x,y;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y;
	cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9;
	cin>>b1>>b2>>b3>>b4>>b5>>b6>>b7>>b8>>b9;
	cin>>c1>>c2>>c3>>c4>>c5>>c6>>c7>>c8>>c9;
	cin>>d1>>d2>>d3>>d4>>d5>>d6>>d7>>d8>>d9;
	if(x==y){
		cout<<1;
	}else{
		cout<<0;
	}
	cin>>s>>z;
	char a,b,c,d,f;
	a='A';
	b='B';
	c='C';
	d='D';
	f='F';
	if(a1==c1||a2==c2||a2==c2||a3==c3||a4==c4||a5==c5||a6==c6||a7==c7||a8==c8||a9==c9||b1==d1||b2==d2||b3==d3||b4==d4||b5==d5||b6==d6||b7==d7||b8==d8||b9==d9)
	{
		cout<<1;
	}else{
		cout<<0;
	}
	if(s==a&&z==b||s==b&&z==c||s==d&&z==f){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
