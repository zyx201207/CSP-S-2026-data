#include<bits/stdc++.h>
using namespace std;
int x,y,p,q;
char m,n;
string c1,s1,c2,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {
		cout<<"0000";
		return 0;
	} else {
		x=(s1[0]-'0')*10+(s1[1]-'0');
		y=(s2[0]-'0')*10+(s2[1]-'0');
		if(x!=y) {
			cout<<"1000";
			return 0;
		} else {
			m=s1[2],n=s2[2];
			p=m-'A',q=n-'A';
			if(p>q) swap(p,q);
			if(p<=2&&q>2) {
				cout<<"1100";
				return 0;
			} else {
				if(p==0&&q==2) {
					cout<<"1110";
					return 0;
				} else {
					cout<<"1111";
				}
			}
		}
	}
	return 0;
}
