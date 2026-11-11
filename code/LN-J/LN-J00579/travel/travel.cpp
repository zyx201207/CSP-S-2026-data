#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	int a=0,b=0;
	int o=0,p=0,q=0,r=0;
	if(c==cc){
		o=1;
		if((s[0]==ss[0])&&(s[1]==ss[1])){
			p=1;
			if((s[2]=='A')||(s[2]=='B')||(s[2]=='C'))a=1;
			else a=2;
			if((ss[2]=='A')||(ss[2]=='B')||(ss[2]=='C'))b=1;
			else b=2;
			if(a==b){
				q=1;
				if(s[2]=='A')
					if(ss[2]=='B')r=1;
					else r=0;
				else if(s[2]=='B')
					if(ss[2]=='A'||ss[2]=='C')r=1;
					else r=0;
				else if(s[2]=='C')
					if(ss[2]=='B')r=1;
					else r=0;
				else if(s[2]=='D'&&ss[2]=='E')r=1;
				else if(s[2]=='E'&&ss[2]=='D')r=1;
				else r=0;
			}
			else q=0;
		}
		else p=0;
	}
	else o=0;
	cout<<o<<p<<q<<r;
	cout<<"\n";
	return 0;
}
