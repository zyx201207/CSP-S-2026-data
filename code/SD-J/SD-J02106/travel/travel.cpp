#include<bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2;
char z1,z2;
string s1,s2;
bool f[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1=(s1[0]-'0')*10+s1[1]-'0';
	p2=(s2[0]-'0')*10+s2[1]-'0';
	z1=s1[2],z2=s2[2];
//	cout<<p1<<' '<<z1<<'\n'<<p2<<' '<<z2<<'\n';
	if(c1==c2){
		f[1]=1;
		if(p1==p2){
			f[2]=1;
			if((z1<='C'&&z2<='C') || (z1>'C'&&z2>'C')){
				f[3]=1;
				if(abs(z1-z2)==1 || (z1=='D'&&z2=='F')) f[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<f[i];
	return 0;
}
