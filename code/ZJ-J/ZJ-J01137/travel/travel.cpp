#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,a1,a2,b1,b2,d1,d2;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=(c1[0]-48)*10+c1[1]-48;
	a2=(c2[0]-48)*10+c2[1]-48;
	b1=(s1[0]-48)*10+s1[1]-48;
	b2=(s2[0]-48)*10+s2[1]-48;
	if(s1[2]!='F') d1=s1[2]-64;
	else d1=s1[2]-65;
	if(s2[2]!='F') d2=s2[2]-64;
	else d2=s2[2]-65;
	if(a1!=a2){
		a=0;
		b=0;
		c=0;
		d=0;
	}else{
		a=1;
		if(b1!=b2){
			b=0;
			c=0;
			d=0;
		}else{
			b=1;
			if((d1<=3&&d2<=3)||(d1>=4&&d2>=4)){
				c=1;
				if(abs(d1-d2)==1){
					d=1;
				}else{
					d=0;
				}
			}else{
				c=0;
				d=0;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}

