#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>c1>>s2>>c2;
	if((s1=="02"&&s2=="02")&&((c1[0]!='0'&&c1[1]!='1')||(c1[0]!='1'&&c1[1]!='6'))){
		cout<<"1";
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			cout<<"1";
			if (((c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'))||((c1[2]=='D'||c1[2]=='F')&&(c2[2]=='D'||c2[2]=='F'))){
				cout<<"1";
				if ((c1[2]+1==c2[2])||(c1[2]-1==c2[2]))cout<<"1";
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}