#include <bits/stdc++.h>
using namespace std;
string s1,s2,s11,s22;
int a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s1;
	cin>>s11;
	cin>>s2;
	cin>>s22;
	if(s1!=s2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s11[0]!=s22[0] || s11[1]!=s22[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	a=abs(int(s11[2])-int(s22[2]));
	if((s11[2]=='D' && s22[2]!='F') || (s11[2]=='F' && s22[2]!='D') || (s22[2]=='D' && s11[2]!='F') || (s22[2]=='F' && s11[2]!='D')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(a==1 || (s11[2]=='D' && s22[2]=='F') || (s11[2]=='F' && s22[2]=='D')){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
