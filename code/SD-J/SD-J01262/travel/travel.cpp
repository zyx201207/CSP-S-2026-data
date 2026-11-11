#include<bits/stdc++.h> 
using namespace std;
int n,m;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	n=s2[2]-'0';
	m=s4[2]-'0';
	if(s1==s3){
		cout<<"1";
		if(s2[0]==s4[0]&&s2[0]==s4[0]){
			cout<<"1";
			if((s2[2]-'A'<=2&&s4[2]-'A'<=2)||(s2[2]-'A'>2&&s4[2]-'A'>2)){
				cout<<"1";
				if(n-m==1||m-n==1){
					cout<<"1";
					}
					else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	

	return 0;
}
