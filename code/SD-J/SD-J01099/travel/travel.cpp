#include<bits/stdc++.h>
using namespace std;
string s,t,ss,tt;
int a[]={1,1,1,2,0,2},b[]={1,2,3,4,5,6};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>t>>ss>>tt;
	if(s!=ss){
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	if(t[0]!=tt[0]||t[1]!=tt[1]){
		cout<<"000";
		return 0;
	}
	cout<<'1';
	if(a[t[2]-'A']!=a[tt[2]-'A']){
		cout<<"00";
		return 0;
	}
	cout<<'1';
	if(b[t[2]-'A']-b[tt[2]-'A']>1) cout<<'0';
	else cout<<'1';
	return 0;
}
