#include<bits/stdc++.h>
using namespace std;

string c1;
string s1;
string c2;
string s2;

int che1=0;
int che2=0;
int pai1=0;
int pai2=0;
bool ce1;
bool ce2;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	
	che1+=(c1[0]-'0')*10;
	che1+=(c1[1]-'0');
	che2+=(c2[0]-'0')*10;
	che2+=(c2[1]-'0');
	pai1+=(s1[0]-'0')*10+(s1[1]-'0');
	pai2+=(s2[0]-'0')*10+(s2[1]-'0');
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') ce1=false;
	else ce1=true;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') ce2=false;
	else ce2=true;
	
	if(che1==che2){
		cout<<"1";
		if(pai1==pai2){
			cout<<"1";
			if(ce1==ce2){
				cout<<"1";
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	//cout<<che1;
	return 0;
}