//heyuanwei xiantieyizhongxue SN-J00705 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=20;
string s[maxn];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++)cin>>s[i];
	cout<<"1";
	if(s[2][0]==s[4][0]&&s[2][1]==s[4][1]){
		cout<<"1";
		if((s[2][2]=='A'||s[2][2]=='B'||s[2][2]=='C')&&(s[4][2]=='A'||s[4][2]=='B'||s[4][2]=='C')){
			cout<<"1";
			if((s[2][2]=='A'&&s[4][2]=='B')||(s[4][2]=='A'&&s[2][2]=='B')||(s[2][2]=='C'&&s[4][2]=='B')||(s[4][2]=='C'&&s[2][2]=='B')){
				cout<<"1"<<endl;
				return 0;
			}
			else{
				cout<<"0"<<endl;
				return 0;
			}
		}
		else if((s[2][2]=='D'||s[2][2]=='F')&&(s[4][2]=='D'||s[4][2]=='F')){
			cout<<"11"<<endl;
			return 0;
		}
		else{
			cout<<"00"<<endl;
			return 0;
		}
	}
	else{
		cout<<"000"<<endl;
		return 0;
	}
	return 0;
}
