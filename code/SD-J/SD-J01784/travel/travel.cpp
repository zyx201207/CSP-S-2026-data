#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int r,x,rr,xx;
map<char,bool> m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	r=(s[0]-'0')*10+s[1]-'0';
	x=(ss[0]-'0')*10+ss[1]-'0';
	rr=s[2];
	xx=ss[2];
	m['A']=m['B']=m['C']=0;
	m['D']=m['F']=1;
	cout<<(c==cc)<<(c==cc&&r==x)<<(c==cc&&r==x&&m[rr]==m[xx])<<(c==cc&&r==x&&m[rr]==m[xx]&&abs(int(rr-xx))==1);
	return 0;
}
