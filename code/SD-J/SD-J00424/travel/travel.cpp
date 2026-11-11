#include<bits/stdc++.h>
using namespace std;
string n,m;
int a[100005];
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string s1,s2;
	cin>>n>>s1>>m>>s2;
	if(n==m) cout<<1;
	else{cout<<"0000";return 0;}
	int bjd1=s1[0]+s1[1],bjd2=s2[0]+s2[1];
	if(bjd1==bjd2) cout<<1;
	else{cout<<"000";return 0;}
	if((s1[2]>'C'&&s2[2]>'C')||(s1[2]<'D'&&s2[2]<'D')) cout<<1;
	else{cout<<"00";return 0;}
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){cout<<1;return 0;}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) cout<<1;
	else cout<<"0";
	return 0;
}
