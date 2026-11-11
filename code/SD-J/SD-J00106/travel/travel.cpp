#include <bits/stdc++.h>
using namespace std;
int sol(string x) {
	int shuzi=0;
	for(int i=0;i<x.size();i++) {
		if(x[i]>='0'&&x[i]<='9') {
			shuzi=shuzi*10+(x[i]-'0');
		}
	}
	return shuzi;
}
bool f(char c,char d) {
	if((c>='A'&&c<='C'&&d>='A'&&d<='C')||(c>='D'&&c<='F'&&d>='D'&&d<='F')) {
		return true;
	}
	return false;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string cc1,cc2,ss1,ss2;
	cin>>cc1>>ss1>>cc2>>ss2;
	if(cc1==cc2) {
		cout<<1;
		int a=sol(ss1);
		int b=sol(ss2);
		if(a==b) {
			cout<<1;
			int n=ss1.size();
			int m=ss2.size();
			if(f(ss1[n-1],ss2[m-1])) {
				cout<<1;
				if(ss1[n-1]+1==ss2[m-1]||ss1[n-1]-1==ss2[m-1]) {
					cout<<1;
				}
				else {
					cout<<0;
				}
			}
			else {
				cout<<"00";
			}
		}
		else {
			cout<<"000";
			return 0;
		}
	}
	else {
		cout<<"0000";
		return 0;
	}
	return 0;
}
