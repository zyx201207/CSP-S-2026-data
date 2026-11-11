#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1;
	mp['B']=2;
	mp['C']=3;
	mp['D']=4;
	mp['F']=5;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cr,rr,cx,rx;
	char sr,sx;
	cr=c1[0]*10+c1[1]-48*11;
	cx=c2[0]*10+c2[1]-48*11;
	rr=s1[0]*10+s1[1]-48*11;
	rx=s2[0]*10+s2[1]-48*11;
	sr=s1[2];
	sx=s2[2];
	cout<<(cr==cx)<<((cr==cx)&&(rr==rx));
	cout<<(((cr==cx)&&(rr==rx))&&((mp[sr]>3)==(mp[sx]>3)));
	cout<<((((cr==cx)&&(rr==rx))&&((mp[sr]>3)==(mp[sx]>3)))&&(((mp[sx]%5+1)==mp[sr])||((mp[sr]%5+1)==mp[sx])));
}

