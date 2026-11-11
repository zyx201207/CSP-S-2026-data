#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,bb,dd;
long long l1,l2;
char x,y;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else{
		cout<<1;bb=b[0];dd=d[0];bb=bb+b[1];dd=dd+d[1];
		if(bb!=dd)cout<<"000";
		else{
			cout<<1;
			x=b[2];y=d[2];
			if(x>='D'&&y<='C'||x<='C'&&y>='D')cout<<"00";
			else{
				cout<<1;
				if(x=='D'&&y=='C'||y=='D'&&x=='C')cout<<0;
				else {
					l1=int(x);
					l2=int(y);
					if(abs(l1-l2)==1)cout<<1;
					else if(x=='D'&&y=='F'||x=='F'&&y=='D')cout<<1;
					else cout<<0;
				}
			}
		}
	}
	return 0;
}