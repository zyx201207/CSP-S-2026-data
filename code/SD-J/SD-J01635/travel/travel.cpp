#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int h1,p1,h2,p2;
char cc1,cc2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		p1=(s1[0]-'0')*10+s1[1]-'0';
		p2=(s2[0]-'0')*10+s2[1]-'0';
		if(p1==p2){
			cout<<1;
			cc1=s1[2];
			cc2=s2[2];
			if(cc1>='A'&&cc1<='C'&&cc2>='A'&&cc2<='C'||cc1>='D'&&cc1<='F'&&cc2>='D'&&cc2<='F'){
				cout<<1;
				if(abs(p2-p1)==1&&cc1==cc2||p2-p1==0&&abs(cc2-cc1)==1)
				cout<<1;
				else
				cout<<0;
			}
			else
			cout<<"00";
		}
		else
		cout<<"000";
	}
	else
	cout<<"0000";
	return 0;
}
