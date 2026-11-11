#include<bits/stdc++.h>
using namespace std;
int a[10]={0,0,0,1,0,1};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			cout<<"1";
			if(a[s1[2]-'A']==a[s2[2]-'A']){
				cout<<"1";
				if((s1[2]=='A'&&s1[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}else{
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}