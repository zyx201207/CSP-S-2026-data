#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c_r,c_x;
string s_r,s_x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_r>>s_r>>c_x>>s_x;
	if(c_r==c_x){
		cout<<1;
		if(s_r[0]==s_x[0]&&s_r[1]==s_x[1]){
			cout<<1;
			if(s_r[2]=='A'&&s_x[2]=='B' || s_r[2]=='A'&&s_x[2]=='C' || s_r[2]=='B'&&s_x[2]=='A' || s_r[2]=='B'&&s_x[2]=='C' || s_r[2]=='C'&&s_x[2]=='A' || s_r[2]=='C'&&s_x[2]=='B' || s_r[2]=='D'&&s_x[2]=='F' || s_r[2]=='F'&&s_x[2]=='D'){
				cout<<1;
				if(s_r[2]=='A'&&s_x[2]=='B' || s_r[2]=='B'&&s_x[2]=='C' || s_r[2]=='B'&&s_x[2]=='A' || s_r[2]=='C'&&s_x[2]=='B' || s_r[2]=='D'&&s_x[2]=='F' || s_r[2]=='F'&&s_x[2]=='D'){
					cout<<1;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0; 
	}
	return 0;
}
