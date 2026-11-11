#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
char k[]={'A','B','C','D','F'};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	bool f1=(a==c),f2=(f1 && b[0]==d[0] && b[1]==d[1]),f3=0,f4=0;
	for (int i=0;i<3 && f2;i++)
		for (int j=0;j<3;j++) if (b[2]==k[i] && d[2]==k[j]) f3=1;
	for (int i=3;i<5 && f2;i++)
		for (int j=3;j<5;j++) if (b[2]==k[i] && d[2]==k[j]) f3=1;
	for (int i=0;i<2 && f3;i++)
		if ((b[2]==k[i] && d[2]==k[i+1]) || (b[2]==k[i+1] && d[2]==k[i])) f4=1;
	if ((b[2]==k[3] && d[2]==k[4]) || (b[2]==k[4] && d[2]==k[3])) f4=1;
	cout << f1 << f2 << f3 << f4;
	return 0;
}
