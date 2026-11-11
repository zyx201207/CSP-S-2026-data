#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			char e=b[2],f=d[2];
			if((e=='A'&&f=='B')||(e=='A'&&f=='C')||(e=='B'&&f=='C')||(e=='B'&&f=='A')||(e=='C'&&f=='A')||(e=='C'&&f=='B')||(e=='D'&&f=='F')||(e=='F'&&f=='D')){
				cout<<1;
				if((e=='A'&&f=='B')||(e=='B'&&f=='C')||(e=='B'&&f=='A')||(e=='C'&&f=='B')||(e=='D'&&f=='F')||(e=='F'&&f=='D')){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}//100pts
