#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		a[1]=1;
		int b=s1[0]-'0',c=s1[1]-'0',b1=s2[0]-'0',c3=s2[1]-'0';
		b=b*10+c;
		b1=b1*10+c3;
		if(b==b1) {
			a[2]=1;
			if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')) {
				a[3]=1;
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')) {
					a[4]=1;
				}
			} else if((s1[2]>='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) {
				a[3]=1;
				a[4]=1;
			}
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}

