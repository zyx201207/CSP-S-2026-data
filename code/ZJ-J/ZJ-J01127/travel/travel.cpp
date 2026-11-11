#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,s,t;
ll box1,box2,pai1,pai2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>s>>b>>t;
	for(ll i=0;i<a.size();i++)box1=box1*10+a[i]-'0';
	for(ll i=0;i<b.size();i++)box2=box2*10+b[i]-'0';
	for(ll i=0;s[i]>='0'&&s[i]<='9';i++)pai1=pai1*10+s[i]-'0';
	for(ll i=0;t[i]>='0'&&t[i]<='9';i++)pai2=pai2*10+t[i]-'0';
	if(box1==box2){
		cout<<1;
		if(pai1==pai2){
			cout<<1;
			if((s[2]<='C'&&t[2]<='C')||(s[2]>'C'&&t[2]>'C')){
				cout<<1;
				if(abs(s[2]-t[2])==1)cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
