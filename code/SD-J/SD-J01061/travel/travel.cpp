#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){return ((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))||((a=='D'||a=='F')&&(b=='D'||b=='F'));}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(check(b[2],d[2])){
				cout<<1;
				if(b[2]=='D'||b[2]=='F'||b[2]=='B'||d[2]=='B') cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
    return 0;
}
