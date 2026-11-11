# include <bits/stdc++.h>
using namespace std;
bool cmp(string s,string x){
	if(s[2]=='D'){
		if(x[2]!='F') return 0;
		else return 1;
	}
	if(s[2]=='F'){
		if(x[2]!='D') return 0;
		else return 1;
	}
	if(x[2]=='D'){
		if(s[2]!='F') return 0;
		else return 1;
	}
	if(x[2]=='F'){
		if(s[2]!='D') return 0;
		else return 1;
	}
	return 1;
}
bool Xcmp(string s,string x){
	if(s[2]=='A') return x[2]=='B';
	if(s[2]=='B') return x[2]=='A'||x[2]=='C';
	if(s[2]=='C') return x[2]=='B';
	if(s[2]=='D') return x[2]=='F';
	if(s[2]=='F') return x[2]=='D';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,pr,cx,sx,px;
	cin>>cr>>sr>>cx>>sx;
	pr=sr[0];
	pr+=sr[1];
	px=sx[0];
	px+=sx[1];
	if(cr!=cx) cout<<"0000";
	else{
		if(pr!=px) cout<<"1000";
		else{
			if(cmp(sr,sx)==0) cout<<"1100";
			else{
				if(Xcmp(sr,sx)==0) cout<<"1110";
				else cout<<"1111";
			}
		}
	} 
	return 0;
} 
//Trick||Treat!
