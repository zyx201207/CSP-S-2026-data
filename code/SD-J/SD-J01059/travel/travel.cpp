#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
		int x,y;
		x=(c2[0]-'0')*10+(c2[1]-'0');
		y=(s2[0]-'0')*10+(s2[1]-'0');
		if(x==y){
			cout<<1;
			if((c2[2]<='C'&&s2[2]<='C')||(c2[2]>='D'&&s2[2]>='D')){
				cout<<1;
				if((c2[2]=='A'&&s2[2]=='B')||
				(c2[2]=='B'&&s2[2]=='A')||
				(c2[2]=='B'&&s2[2]=='C')||
				(c2[2]=='C'&&s2[2]=='B')||
				(c2[2]=='D'&&s2[2]=='F')||
				(c2[2]=='F'&&s2[2]=='D')){
					cout<<1;
				}
				else{
					cout<<0;
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

