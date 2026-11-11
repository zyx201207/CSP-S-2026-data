#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if(a=='A'&&b=='B'||a=='B'&&b=='C'||b=='A'&&a=='B'||b=='B'&&a=='C') return 1;
	if(a=='D'&&b=='F'||b=='D'&&a=='F') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int ca,cb;
	int aa=0,ab=0;
	char xa,xb;
	char c;
	cin>>ca;
	cin>>c; aa=aa*10+c-'0';
	cin>>c; aa=aa*10+c-'0';
	cin>>xa;
	cin>>cb;
	cin>>c; ab=ab*10+c-'0';
	cin>>c; ab=ab*10+c-'0';
	cin>>xb;
	if(ca==cb){
		cout<<1;
		if(aa==ab){
			cout<<1;
			if(xa<='C'&&xb<='C'||xa>='D'&&xb>='D'){
				cout<<1;
				if(check(xa,xb)) cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
