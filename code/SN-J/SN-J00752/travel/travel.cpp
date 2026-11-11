//SN-J00752 杨济铭 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string l1=s1.substr(0,2),l2=s2.substr(0,2);
	char r1=s1[2],r2=s2[2];
	bool a=(c1==c2),b=a&&(l1==l2),c=b&&((r1<'A'+3)==(r2<'A'+3)),d=c&&(((r1<'A'+3)&&(r2<'A'+3)&&abs(r1-r2)==1)||((r1>'A'+2)&&(r2>'A'+2)&&abs(r1-r2)==2));
	cout<<a<<b<<c<<d;
	return 0;
}
