#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in" ,"r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<'1';
			char a1=s1[2];
			char a2=s2[2];
			if(a1=='D'){
				if(a2=='E'){
					cout<<"11";
				}
				else cout<<"00";
			}
			if(a1=='E'){
				if(a2=='D') cout<<"11";
				else cout<<"00";
			}
			if(a1=='A'){
				if(a2=='B') cout<<"11";
				else if(a2=='C') cout<<"10";
				else cout<<"00";
			}
			if(a1=='B'){
				if(a2=='A') cout<<"11";
				else if(a2=='C') cout<<"11";
				else cout<<"00";
			}
			if(a1=='C'){
				if(a2=='B') cout<<"11";
				else if(a2=='A') cout<<"10";
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
