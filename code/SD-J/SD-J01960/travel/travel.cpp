#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	s1=' '+s1;
	s2=' '+s2;
	if(c1==c2){
		cout<<"1";
		if(s1[2]==s2[2]){
			cout<<"1";
			if((s1[3]=='A' && (s2[3]=='B' || s2[3]=='C')) || (s1[3]=='B' && (s2[3]=='A' || s2[3]=='C')) || (s1[3]=='C' && (s2[3]=='A' || s2[3]=='B')) || (s1[3]=='D' && s2[3]=='F') || (s1[3]=='F' && s2[3]=='D')){
				cout<<"1";
				if((s1[3]=='A' && s2[3]=='B') || (s1[3]=='B' && (s2[3]=='C' || s2[3]=='A')) || (s1[3]=='C' && s2[3]=='B') || (s1[3]=='D' && s2[3]=='F') || (s1[3]=='F' && s2[3]=='D')){
					cout<<"1";
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
