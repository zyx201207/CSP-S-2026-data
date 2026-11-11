#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=0,f1=0,f2=0;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0; i<c1.size(); i++) {
		if(c1[i]!=c2[i])
			f=1;
	}
	if(f==1) {
		cout <<"0000";
		return 0;
	} else cout <<"1";
	for(int i=0; i<=1; i++)
		if(s1[i]!=s2[i])
			f1=1;
	if(f1==1) {
		cout<<"000";
		return 0;
	} else cout <<"1";
	char a=s1[2],b=s2[2];
	if((a=='A')||(a=='B')||(a=='C')) {
		if(!((b=='A')||(b=='B')||(b=='C')))
			f2=1;
	} else {
		if(!((b=='D')||(b=='F')))
			f2=1;
	}
	if(f2==1) {
		cout<<"00";
		return 0;
	} else cout <<"1";
	char c=s1[2],d=s2[2];
	int cha=abs(int(c)-int(d));
	if(cha==1)
		cout <<"1";
	else cout <<"0";
	return 0;
}
