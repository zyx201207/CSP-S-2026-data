#include<bits/stdc++.h>
using namespace std;
int c1,s11,c2,s21;
char s12,s22;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s11>>s12>>c2>>s21>>s22;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s11!=s21){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((s12=='A'&&s22=='B')||(s12=='B'&&s22=='A')) cout<<"11";
	else if((s12=='B'&&s22=='C')||(s12=='C'&&s22=='B')) cout<<"11";
	else if((s12=='D'&&s22=='F')||(s12=='F'&&s22=='D')) cout<<"11";
	else if((s12=='A'&&s22=='C')||(s12=='C'&&s22=='A')) cout<<"10";
	else cout<<"00";
	return 0;
}