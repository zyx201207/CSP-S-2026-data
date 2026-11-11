#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int x1,x2,p1,p2,z1,z2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1=int(c1[0]-48)*10+int(c1[1]-48);
	x2=int(c2[0]-48)*10+int(c2[1]-48);
	p1=int(s1[0]-48)*10+int(s1[1]-48);
	p2=int(s2[0]-48)*10+int(s2[1]-48);
	z1=int(s1[2]-64);
	z2=int(s2[2]-64);
	if(x1==x2){
		cout<<1;
		a++;
	}
	else{
		cout<<0;
	}
	if(a && p1==p2){
		cout<<1;
		b++;
	}
	else{
		cout<<0;
	}
	if(a && b && ((z1>=1 && z1<=3 && z2>=1 && z2<=3) || (z1>=4 && z1<=5 && z2>=4 && z2<=5))){
		cout<<1;
		c++;
	}
	else{
		cout<<0;
	}
	if(a && b && c && (abs(z1-z2)==1)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
