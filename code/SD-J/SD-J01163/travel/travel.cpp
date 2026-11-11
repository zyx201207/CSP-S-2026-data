#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m) {
		cout<<1;
		bool t=true;
		for(int i=0; i<2; i++) {
			if(a[i]!=b[i]) {
				t=false;
			}
		}
		if(t==true) {
			cout<<1;
			char a2=a[2],b2=b[2];
			if((a2<='F' && a2>='D' && b2<='F' && b2>='D') || (a2<='C' && a2>='A' && b2<='C' && b2>='A')) {
				cout<<1;
				if((a2=='A' && b2=='C') || (b2=='A' && a2=='C')) {
					cout<<0;
				} else {
					cout<<1;
				}
			} else {
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
//分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++;
	return 0;
}
