#include<bits/stdc++.h>
using namespace std;
string c_a,s_a,c_b,s_b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_a>>s_a>>c_b>>s_b;
	if(c_a==c_b){
		cout<<1;
		if(s_a[0]==s_b[0]&&s_a[1]==s_b[1]){
			cout<<1;
			if(((s_a[2]>='A'&&s_a[2]<='C')&&(s_b[2]>='A'&&s_b[2]<='C'))||((s_a[2]=='D'||s_a[2]=='F')&&(s_b[2]=='D'||s_b[2]=='F'))){
				cout<<1;
				if((s_a[2]=='A'&&s_b[2]=='B')||(s_a[2]=='B'&&s_b[2]=='A')||(s_a[2]=='B'&&s_b[2]=='C')||(s_a[2]=='D'&&s_b[2]=='F')||(s_a[2]=='F'&&s_b[2]=='D')){
					cout<<1;
					return 0;
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
