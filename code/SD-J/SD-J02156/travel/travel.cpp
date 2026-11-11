#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string c1,c2,s1,s2;bool b=1;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {cout<<"0000";return 0;}
	int i=0; string k1,k2;
	while(i<=1){
		k1+=s1[i];k2+=s2[i];
		i++;
	}
	char h1=s1[2],h2=s2[2];
	if(k1==k2)cout<<1;
	else {cout<<"000";return 0;}
	if(h1=='D'&&h2=='F'||h2=='D'&&h1=='F')cout<<1;
	else if(h1=='A'&&h2=='B'||h1=='A'&&h2=='C')cout<<1;
	else if(h1=='B'&&h2=='A'||h1=='B'&&h2=='C')cout<<1;
	else if(h1=='C'&&h2=='A'||h1=='C'&&h2=='B')cout<<1;
	else {cout<<"00";return 0;}
	if(h1=='D'&&h2=='F'||h2=='D'&&h1=='F')cout<<1;
	else if(h1=='A'&&h2=='B'||h1=='B'&&h2=='A')cout<<1;
	else if(h1=='B'&&h2=='C'||h1=='C'&&h2=='B')cout<<1;
	else cout<<"0";
	return 0;
}
