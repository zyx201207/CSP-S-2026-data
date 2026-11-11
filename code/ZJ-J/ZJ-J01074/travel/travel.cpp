#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<1;
		int s11=(s1[0]-'0')*10+(s1[1]-'0');
		int s21=(s2[0]-'0')*10+(s2[1]-'0');
		if(s11!=s21){
			cout<<"000";
		}
		else{
			cout<<1;
			if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
				cout<<"11";
			}
			else if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
	}
	return 0;
}
