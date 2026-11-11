#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) {
		cout<<1;
		int n,m;
		n=(b[0]-'0')*10+(b[1]-'0');
		m=(d[0]-'0')*10+(d[1]-'0');
		if(n==m) {
			cout<<1;
			char c,h;
			c=b[2];
			h=d[2];
			if(c=='F'||c=='D') {
				if(h=='F'||h=='D') {
					cout<<1;
				} else {
					cout<<"00";
					return 0l;
				}
			} else {
				if(h=='A'||h=='B'||h=='C') {
					cout<<1;
				} else {
					cout<<"00";
					return 0;
				}
			}
			if((c=='C'&&h=='A')||(c=='A'&&h=='C')){
				cout<<0;
				return 0;
			}else{
				cout<<1;
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}/*
嵊州市新城实验学校909，ZHY LOVE ZZQ  
我的洛谷:yeweibo 
*/ 
