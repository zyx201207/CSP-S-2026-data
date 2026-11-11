#include<bits/stdc++.h>
using namespace std;
bool b[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	int d1=(c1[0]-'0')*10+(c1[1]-'0'),d2=(c2[0]-'0')*10+(c2[1]-'0');
	if(d1==d2){
		b[1]=1;
	}
	d1=(s1[0]-'0')*10+(s1[1]-'0');
	d2=(s2[0]-'0')*10+(s2[1]-'0');
	if(d1==d2 &&b[1]){
		b[2]=1;
	}
	d1=s1[2];
	d2=s2[2];
	if(((d1>='A'&& d1<='C'&& d2>='A'&& d2<='C')||(d1>='D'&& d1<='F' && d2>='D'&& d2<='F'))&&b[2]){
		b[3]=1;
	}
	if(abs(d1-d2)==1 &&b[3]){
		b[4]=1;
	}
	for(int i=1;i<=4;i++){
		if(b[i])cout<<1;
		else cout<<0;
	}
	return 0;
}
