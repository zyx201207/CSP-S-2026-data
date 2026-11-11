#include <bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s1>>s2>>t1>>t2;
	if (s1!=t1){
		cout<<"0000\n";
		return 0;
	}
	cout<<1;
	if (s2[0]!=t2[0]||s2[1]!=t2[1]){
		cout<<"000\n";
		return 0;
	}
	cout<<1;
	if ((s2[2]<'D')!=(t2[2]<'D')){
		cout<<"00\n";
		return 0;
	}
	cout<<1;
	if (s2[2]>t2[2]) swap(s2[2],t2[2]);
	if ((s2[2]=='A'&&t2[2]=='B')||
		(s2[2]=='B'&&t2[2]=='C')||
		(s2[2]=='D'&&t2[2]=='F')) cout<<"1\n";
	else cout<<"0\n";
	return 0;
}
