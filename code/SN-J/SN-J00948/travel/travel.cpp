#include<bits/stdc++.h>
using namespace std;

string s1,s2;
long long c1,c2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int wow=0,bob=0;
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='C'||s2[2]=='B'||s2[2]=='A'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
		bob=1;
	}
	if((s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||((s2[2]=='B'&&(s1[2]=='A'||s1[2]=='C')))||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
		wow=1;
	}
	
	
	
	if(c1==c2){
		cout<<1;
		if(s1[1]==s2[1]){
			cout<<1;
			if(bob){
				cout<<1;
				if(wow){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	
	return 0;
}
