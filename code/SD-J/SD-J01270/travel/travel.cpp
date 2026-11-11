#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,a,b,cnt,cnt1,res;
string s[3],s1[3];
double t;
bool vis;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[0]>>s[1]>>s1[0]>>s1[1];
	if(s[0]==s1[0]){
		cout<<'1';
		if(s[1][0]==s1[1][0]&&s[1][1]==s1[1][1]){
			cout<<'1';
			if(((s[1][2]=='A'||s[1][2]=='B'||s[1][2]=='C')&&(s1[1][2]=='A'||s1[1][2]=='B'||s1[1][2]=='C'))){
				cout<<'1';
				if((s[1][2]=='A'&&s1[1][2]=='B')||(s[1][2]=='B'&&s1[1][2]=='C')||(s1[1][2]=='B'&&s[1][2]=='C')||(s[1][2]=='B'&&s1[1][2]=='A')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if((s[1][2]=='E'||s[1][2]=='D')&&(s1[1][2]=='E'||s1[1][2]=='D')){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
