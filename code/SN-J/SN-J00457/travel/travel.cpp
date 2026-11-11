#include <bits/stdc++.h>
using namespace std;
string a,b; //A=65,0=48;
int n,m;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m) {
		cout<<1;
		int aa=((int(a[0])-48)*10)+int(a[1]-48),bb=((int(b[0])-48)*10)+int(b[1]-48);//我的变量名字是不是特别猎奇
		int aaa=int(a[2])-64,bbb=int (b[2])-64;
		if(aa==bb) {
			cout<<1;
			if((aaa<=3&&bbb<=3)||(aaa>3&&bbb>3)) {
				cout<<1;
				if(aaa==bbb-1||bbb==aaa-1) {
					cout<<1;
				} else {
					cout<<0;
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
	return 0;
}
