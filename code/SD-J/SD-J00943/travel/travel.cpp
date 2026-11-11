#include<bits/stdc++.h>
#define ac ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ac;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
	}
	else{
		cout<<"1";
		int a1,a2;
		a1=(s2[0]-'0')*10+(s2[1]-'0');
		a2=(s4[0]-'0')*10+(s4[1]-'0');
		if(a1!=a2){
			cout<<"000";
		}
		else{
			cout<<"1";
			if(s2[2]<='C'&&s4[2]<='C'){
				cout<<"1";
				if(abs((s2[2]-'A')-(s4[2]-'A'))==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(s2[2]>='D'&&s4[2]>='D'){
				cout<<"11";
			}
			else{
				cout<<"00"; 
			}
		}
	}
	return 0;
}

