#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b,p1,p2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	p1=s1[0]-'0';
	p1=p1*10+(s1[1]-'0');
	p2=s2[0]-'0';
	p2=p2*10+(s2[1]-'0');
	a=s1[2]-'A'+1;
	b=s2[2]-'A'+1;
	
	if(c1==c2){
		cout<<"1";
		if(p1==p2){
			cout<<"1";
			if((a<=3 && b<=3) || (a>3 && a<=5 && b>3 && b<=5)){
				cout<<"1";
				if(abs(a-b)==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";

	return 0;
}
