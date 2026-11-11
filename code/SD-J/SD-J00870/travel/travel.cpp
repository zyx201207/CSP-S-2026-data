#include<bits/stdc++.h>
using namespace std;//powered_by_flyin2899

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int p1=(s1[0]-'0')*10+s1[1]-'0',p2=(s2[0]-'0')*10+s2[1]-'0';
	char n1=s1[2],n2=s2[2];
	cout<<int(c1==c2);
	cout<<int(c1==c2&&p1==p2);
	cout<<int(c1==c2&&p1==p2&&!(n1<='C'^n2<='C'));
	cout<<int(c1==c2&&p1==p2&&!(n1<='C'^n2<='C')&&abs(n1-n2)==1);
	return 0;
}
