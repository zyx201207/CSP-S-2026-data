#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int cx=0,yp=0,yc=0,xl=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	string p1,p2,h1,h2;
	p1=c1[0]+c1[1];
	p2=c2[0]+c2[1];
	h1=c1[2];
	h2=c2[2];
	if(s1==s2) cx=1;
	if(cx&&p1==p2) yp=1;
	if(yp){
		if(h1=="A"){
			if(h2=="B"||h2=="C") yc=1;
		}
		else if(h1=="C"){
			if(h2=="B"||h2=="A") yc=1;
		}
		else if(h1=="B"){
			if(h2=="A"||h2=="C") yc=1;
		}
		else if(h1=="D"){
			if(h2=="F") yc=1,xl=1;
		}
		else if(h1=="F"){
			if(h2=="D") yc=1,xl=1;
		}
	}
	if(yc&&!xl){
		if(h1=="A"){
			if(h2=="B") xl=1;
		}
		else if(h1=="C"){
			if(h2=="B") xl=1;
		}
		else if(h1=="B"){
			if(h2=="A"||h2=="C") xl=1;
		}
	}
	cout<<cx<<yp<<yc<<xl;
	return 0;
}