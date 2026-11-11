#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
map<char,bool> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1;
	mp['B']=1;
	mp['C']=1;
	mp['D']=0;
	mp['F']=0;
	cin>>a>>b>>c>>d;
	int cxr=(a[0]-'0')*10+(a[1]-'0'),cxx=(c[0]-'0')*10+(c[1]-'0');
	if(cxr!=cxx){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int phr=(b[0]-'0')*10+(b[1]-'0'),phx=(d[0]-'0')*10+(d[1]-'0');
	if(phr!=phx){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	char x=b[2],r=d[2];
	if(mp[x]!=mp[r]){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if((x=='A' and r=='B') or (x=='B' and r=='A') or (x=='B' and r=='C') or (x=='C' and r=='B') or (x=='D' and r=='F') or (x=='F' and r=='D'))
		cout<<"1";
	else cout<<"0";
	return 0;
}