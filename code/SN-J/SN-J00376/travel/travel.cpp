#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+10;
const ll inf=1e18+10;
string s1,s2,s3,s4;
int f1=0,f2=0,f3=0,f4=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
		f1=1;
	}
	else{
		cout<<"0";
	}
	if(s2.size()==s4.size()&&f1){
		if(s2.size()==3){
			if(s2[0]==s4[0]&&s2[1]==s4[1]){
				cout<<"1";
				f2=1;
			}
			else{
				cout<<"0";
			}
		}
		if(s2.size()==4){
			if(s2[0]==s4[0]&&s2[1]==s4[1]&&s2[2]==s2[2]){
				cout<<"1";
				f2=1;
			}
			else{
				cout<<"0";
			}
		}
	}
	else{
		cout<<"0";
	}
	if(s2.size()==s4.size()&&f1&&f2){
		char a,b;
		if(s2.size()==3){
			a=s2[2];
			b=s4[2];
			if('A'<=a&&'A'<=b&&'C'>=a&&'C'>=b||'F'>=a&&'D'<=a&&'F'>=b&&'D'<=b){
				cout<<'1';
				f3=1;
			}
			else{
				cout<<'0';
			}
		}
		else{
			a=s2[3];
			b=s4[3];
			if('A'<=a&&'A'<=b&&'C'>=a&&'C'>=b||'F'>=a&&'D'<=a&&'F'>=b&&'D'<=b){
				cout<<'1';
				f3=1;
			}
			else{
				cout<<'0';
			}
		}
	}
	else{
		cout<<'0';
	}
	if(s2.size()==s4.size()&&f1&&f2&&f3){
		char a,b;
		if(s2.size()==3){
			a=s2[2];
			b=s4[2];
			if(a=='A'&&b=='B'||a=='B'&&b=='C'||a=='D'&&b=='F'||b=='A'&&a=='B'||b=='B'&&a=='C'||b=='D'&&a=='F'){
				cout<<'1';
			}
			else{
				cout<<'0';
			}
		}
		else{
			a=s2[3];
			b=s4[3];
//			cout<<"---"<<a;
//			cout<<"   "<<b<<"\n";
			if(a=='A'&&b=='B'||a=='B'&&b=='C'||a=='D'&&b=='F'||b=='A'&&a=='B'||b=='B'&&a=='C'||b=='D'&&a=='F'){
				cout<<'1';
			}
			else{
				cout<<'0';
			}
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}
