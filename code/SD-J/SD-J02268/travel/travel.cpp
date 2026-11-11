#include<iostream>
#include<cstdio>
using namespace std;
bool flag[5]={0,0,0,1,1};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	string a3=a2.substr(0,2);
	string b3=b2.substr(0,2);
	char ca=a2[2],cb=b2[2];
	cout<<(a1==b1);
	cout<<(a1==b1&&a3==b3);
	cout<<(a1==b1&&a3==b3&&flag[ca-'A']==flag[cb-'A']);
	cout<<(a1==b1&&a3==b3&&flag[ca-'A']==flag[cb-'A']&&abs(ca-cb)==1);
	cout<<"\n"; 
	return 0;
}
