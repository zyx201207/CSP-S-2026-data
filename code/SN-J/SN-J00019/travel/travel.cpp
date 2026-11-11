#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out", "w",stdout);
	string s;
	string n;
	string m;
	string t;
	cin>>s>>t>>n>>m;
	if(s==n){
		cout<<1;
		if(t[0]==m[0]){
			if(t[1]==m[1]){
				cout<<1; 
				if(t[2]==65&&m[2]==68||t[2]==65&&m[2]==70||t[2]==66&&m[2]==68||t[2]==66&&m[2]==70||t[2]==67&&m[2]==68||t[2]==67&&m[2]==70||t[2]==68&&m[2]==65||t[2]==70&&m[2]==65||t[2]==68&&m[2]==66||t[2]==70&&m[2]==66||t[2]==68&&m[2]==67||t[2]==70&&m[2]==67){
					cout<<"00";
				}
				else{
					cout<<1;
					if(t[2]==67&&m[2]==65||t[2]==65&&m[2]==67){
						cout<<0;
					}
					else{
						cout<<1; 
					}
				}
			}
			else{
				cout<<"000";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
