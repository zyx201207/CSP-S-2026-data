#include<bits/stdc++.h>
using namespace std;
string c,cc,s,ss;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	bool a=(c==cc);
	bool b=(a&&s[0]==ss[0]&&s[1]==ss[1]);
	bool c=(b&&(s[2]<='C'&&ss[2]<='C'||s[2]>='D'&&ss[2]>='D'));
	bool d=(c&&(ss[2]-s[2]==1||s[2]-ss[2]==1));
	cout<<a<<b<<c<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
