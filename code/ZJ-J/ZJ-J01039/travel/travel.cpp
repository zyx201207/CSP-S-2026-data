#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char z[]={'A','B','C','D','E'};
bool ok=false,zw=false;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else  cout<<"0";
	if(s1[0]==s2[0]&&s2[1]==s1[1]&&c1==c2){
		cout<<"1";
		ok=true;
	}
	else cout<<"0";
	if(ok==true){
		if(s1[2]=='A'){
			if(s2[2]=='B'){
				cout<<"1";
				zw=true;
			}
			else if(s2[2]=='C') cout<<"1";
			else cout<<"0";
		}
		if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C'){
				zw=true;
				cout<<"1";
			}
			else cout<<"0";
		}
		if(s1[2]=='C'){
			if(s2[2]=='A'){
				cout<<"1";
			}
			else if(s2[2]=='B'){
				cout<<"1";
				zw=true;
			}
			else cout<<"0";
		}
		if(s1[2]=='D'){
			if(s2[2]=='E'){
				cout<<"1";
				zw=true;
			}
			else cout<<"0";
		}
		if(s1[2]=='F'){
			if(s2[2]=='D'){
				cout<<"1";
				zw=true;
			}
			else cout<<"0";
		}
	}
	else cout<<"0";
	if(ok==true&&zw==true){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}