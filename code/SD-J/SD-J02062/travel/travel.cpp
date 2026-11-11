#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string c,c1,s,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		cout<<"1";
		char zuor=s[0]+s[1];
		char zuox=s1[0]+s1[1];
		if(zuor==zuox){
			cout<<"1";
			char n=s[2];
			char m=s1[2];
			if((n=='A'&&m=='B')||(n=='A'&&m=='C')||(n=='B'&&m=='A')||(n=='B'&&m=='C')||(n=='C'&&m=='A')||(n=='C'&&m=='B')||(n=='D'&&m=='F')||(n=='F'&&m=='D')){
				cout<<"1";
				if(abs(n-m)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else {
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
