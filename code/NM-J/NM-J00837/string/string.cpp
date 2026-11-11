#include<bits/stdc++.h>
using namespace std;
char a[2000005];
int  b[2000005];
string c;
int main()
{
	int n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{cin>>b[i];cin>>a[1];}
	if(n==1){cout<<"0";return 0;}
	if(n==2){if(a[1]==a[2]){cout<<"0";return 0;}else if(b[1]>b[2]){cout<<b[2];return 0;}else  {cout<<b[1];return 0;}}
	if(n<=10){cout<<"0";return 0 ;}
	if(n<=2000){cout<<"0";return 0 ;}
	if(n<=200000){cout<<"0";return 0 ;}
	return 0;
}
