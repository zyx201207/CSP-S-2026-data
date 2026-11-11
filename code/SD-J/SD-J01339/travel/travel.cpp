#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=1e8+10;
string s1,s2,s3,s4; 
bool flag1=0,flag2=0,flag3=0,flag4=0;
int sum1,sum2;
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<'1';
	else cout<<'0';
	for(int i=0;i<=1;i++)
	{
		sum1+=s2[i]-'0';
		sum2+=s4[i]-'0';
	}
	if(sum1==sum2) 
	    cout<<'1';
	else cout<<'0';
	if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D')) 
	{
		flag3=1;
		cout<<'1';
	}
	else cout<<'0';
	int a,b;
	a=s2[2]-'0';
	b=s4[2]-'0';
	if(abs(a-b)==1&&flag3) cout<<'1';
	else cout<<'0';
	return 0;
}
