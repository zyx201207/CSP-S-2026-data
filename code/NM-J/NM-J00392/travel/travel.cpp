#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,cx;
	string sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
		cout<<"1";
	else
		cout<<"0";
	if(sr[0]==sx[0]&&sr[1]==sx[1])
		cout<<"1";
	else
		cout<<"0";
	if(sr[2]=="A"&&s[2]=="B")
		cout<<"1"<<"1";
	if(sr[(2]=="A"&&sx[2]=="C")
		cout<<"1"<<"0";
	if(sr[2]=="B"&&sx[2]=="A")
		cout<<"1"<<"1";
	if(sr[2]=="B"&&sx[2]=="C")
		cout<<"1"<<"1";
	if(sr[2]=="C"&&sx[2]=="A")
		cout<<"1" <<"0";
	if(sr[2]=="C"&&sx[2]=="B")
		cout<<"1"<<"1";
	if(sr[2]=="D"&&sx[2]=="F")
		cout<<"1"<<"1";
	if(sr[2]=="F"&&sx[2]=="D")
		cout<<"1"<<"1";	
	if(sr[2]=="A"&&sx[2]=="D")
		cout<<"0" <<"0";
	if(sr[2]=="A"&&sx[2]=="F")
		cout<<"0" <<"0";
	if(sr[2]=="B"&&sx[2]=="D")
		cout<<"0" <<"0";
	if(sr[2]=="B"&&sx[2]=="F")
		cout<<"0" <<"0";
	if(sr[2]=="C"&&sx[2]=="F")
		cout<<"0" <<"0";
	if(sr[2]=="C"&&sx[2]=="D")
		cout<<"0" <<"0";
	return 0;
}

