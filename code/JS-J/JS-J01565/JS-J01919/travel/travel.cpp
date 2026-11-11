#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1!=c2){
		cout<<"0000"<<'\n';
		//return 0;
	}else{
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			char a=s1[2],b=s2[2];
			if(((a=='A' or a=='B' or a=='C') and (b=='A' or b=='B' or b=='C')) or ((a=='F' or a=='D') and (b=='F' or b=='D'))){
				if((a=='F' and b=='D') or (a=='D' and b=='F') or (a=='C' and b=='B') or (a=='B' and (b=='C' or b=='A')) or (a=='A' and b=='B')){
					cout<<"1111"<<'\n';
				}else{
					cout<<"1110"<<'\n';
				}
			}else{
				cout<<"1100"<<'\n';
			}
		}else{
			cout<<"1000"<<'\n';
		}
	}
	return 0;
}
