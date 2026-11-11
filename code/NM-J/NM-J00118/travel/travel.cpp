#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a=" ",a1=" ",b=" ",b1=" ";
	cin>>a>>a1>>b>>b1;
	string x=" ",y=" ",x1=" ",y1=" ",x2=" ",y2=" ";
	x=a1[0];
	x1=a1[1];
	y=b1[0];
	y1=b1[1];
	x2=a1[2];
	y2=b1[2];
	if(a==b) {
		cout<<1;
		if(x==y&&x1==y1) {
			cout<<1;
			if((x2=="D"||x2=="E")&&(y2=="D"||y2=="E")) {
				cout<<11;
			} else if((x2=="A"||x2=="B"||x2=="C")&&(y2=="A"||y2=="B"||y2=="C")) {
				cout<<1;
				if(x2>y2) {
					int n=a1[2]-b1[2];
					if(n==1) {
						cout<<1;
					} else {
						cout<<0;
					}
				} else {
					int n=b1[2]-a1[2];
					if(n==1) {
						cout<<1;
					} else {
						cout<<0;
					}
				}
			} else {
				cout<<0<<0;
			}
		} else {
			cout<<0<<0<<0;
		}
	} else {
		cout<<"0000";
		return 0;
	}
	return 0;
}
