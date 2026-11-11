#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int _c1=int(c1[0])*10+c1[1],_c2=int(c2[0])*10+c2[1];
	if(_c1!=_c2){
		cout<<"0000";
	}
	else{
		cout<<"1";
		int _s1=int(s1[0])*10+s1[1],_s2=int(s2[0])*10+s2[1];
		if(_s1!=_s2){
			cout<<"000";
		}
		else{
			cout<<"1";
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||
			((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
				cout<<"1";
				if(int(s1[2])-int(s2[2])==1||int(s2[2])-int(s1[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
	}
	return 0;
}
