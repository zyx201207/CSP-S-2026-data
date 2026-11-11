#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
		a[1]=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a[1]==1)
		a[2]=1;
	if(s1[2]>'C'&&s2[2]>'C'&&a[2]==1)
		a[3]=1;
	if(s1[2]<='C'&&s2[2]<='C'&&a[2]==1)
		a[3]=1;
	int t=0;
	int t1=s1[2]-'A'+1;
	int t2=s2[2]-'A'+1;
	if(t1-t2==1||t2-t1==1)
		t=1;
	if(a[3]==1&&t==1)
		a[4]=1;
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}
