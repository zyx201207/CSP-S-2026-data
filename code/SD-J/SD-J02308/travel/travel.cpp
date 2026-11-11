#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string c1,s1;
string c2,s2;
int p1,p2;
char x1,x2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;
	cin>>c2>>s2; 
	for(int i=0;i<2;i++){
		p1=p1*10+(s1[i]-'0');
		p2=p2*10+(s2[i]-'0');
	} 
	x1=s1[2],x2=s2[2]; 
	f1=(c1==c2);  
	f2=(f1&&(p1==p2));
	f3=(f2&&x1<='C'&&(x2<='C'||x1>='D'&&x2>='D'));
	f4=(f3&&(int(x1-x2)==1||int(x1-x2)==-1));
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
