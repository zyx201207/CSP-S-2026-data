#include<bits/stdc++.h>
using namespace std;
string sta1,sta2,stb1,stb2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>sta1>>sta2>>stb1>>stb2;
	if(sta1==stb1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(sta2[0]==stb2[0]&&sta2[1]==stb2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((sta2[2]=='A'&&(stb2[2]=='B'||stb2[2]=='C'))||(sta2[2]=='B'&&(stb2[2]=='A'||stb2[2]=='C'))||(sta2[2]=='C'&&(stb2[2]=='B'||stb2[2]=='A'))||(sta2[2]=='D'&&stb2[2]=='E')||(sta2[2]=='E'&&stb2[2]=='D')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(sta2[2]+1==stb2[2]||sta2[2]==stb2[2]+1) cout<<1;
	else cout<<0;
}
//RP++
