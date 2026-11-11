#include<bits/stdc++.h>
using namespace std;
long long c1,c2,p1,p2;
string s1,s2;
char z1,z2;
long long a=0,b=0,c=0,d=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1=(s1[0]-'0')*10+s1[1]-'0';
	p2=(s2[0]-'0')*10+s2[1]-'0';
	z1=s1[2]; z2=s2[2];
	if(z1=='D') z1='E';
	if(z2=='D') z2='E';
	//cout<<c1<<' '<<p1<<' '<<z1<<' '<<c2<<' '<<p2<<' '<<z2<<endl;
	if(c1==c2) a=1;
	if(a==1&&p1==p2) b=1;
	if(b==1&&(z1<'D'&&z2<'D' || z1>'D'&&z2>'D')) c=1;
	if(c==1 && abs(int(z1)-int(z2))==1) d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
