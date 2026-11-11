#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int l1=0,l2=0;
	l1=(s1[0]-'0')*10+s1[1]-'0';
	l2=(s2[0]-'0')*10+s2[1]-'0';
	if(c1==c2){
		cout<<1;
		if(l1==l2){
			cout<<1;
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')){
				cout<<1;
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
}
