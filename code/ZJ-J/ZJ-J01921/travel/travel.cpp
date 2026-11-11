#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel1.in","r",stdin);
	freopen("traval1.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
		if(s[0]==ss[0] and s[1]==ss[1]){
			cout<<1;
			char x=s[2],y=ss[2];
			if((x=='A' and y=='B')or (x=='B' and y=='A')){
				cout<<"11\n";
			}else if((x=='A' and y=='C') or (x=='C' and y=='A')){
				cout<<"10\n";
			}else if((x=='B' and y=='C') or (x=='C' and y=='B')){
				cout<<"11\n";
			}else if((x=='D' and y=='F') or (x=='F' and y=='D')){
				cout<<"11\n";
			}else{
				cout<<"00\n";
			}
		}else{
			cout<<"000\n";
			return 0;
		}
	}else{
		cout<<"0000\n";
		return 0;
	}
	return 0;
}
