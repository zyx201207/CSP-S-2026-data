#include<bits/stdc++.h>
#define int long long
using namespace std;
int l1,l2;
string c1,c2,s1,s2;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int ch1=(c1[0]-'0')*10+c1[1]-'0';
	int ch2=(c2[0]-'0')*10+c2[1]-'0';
	int se1=(s1[0]-'0')*10+s1[1]-'0';
	int se2=(s2[0]-'0')*10+s2[1]-'0';
	if(ch1==ch2) cout<<1;
	else{cout<<0<<0<<0<<0;return 0;}
	if(se1==se2) cout<<1;
	else{cout<<0<<0<<0;return 0;}
	if(s1[2]=='D'||s1[2]=='F') l1=0;
	else l1=1;
	if(s2[2]=='D'||s2[2]=='F') l2=0;
	else l2=1;
	if(l1==l2){
		cout<<1;
		if(abs(s1[2]-s2[2])==1) cout<<1;
		else cout<<0;
	}
	else cout<<0<<0;
	return 0;
}
