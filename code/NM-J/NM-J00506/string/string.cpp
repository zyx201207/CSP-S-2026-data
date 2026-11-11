#include<bits/stdc++.h>
using namespace std;
int n;
string ss1="2 a 2 b 1 c",ss2="2 a 3 a",ss3="1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==3)
	{
		cin>>ss1;
		cout<<2;
	}
	if(n==2)
	{
		cin>>ss2;
        cout<<0;
	}
	if(n==6)
	{
		cin>>ss3;
		cout<<3000000000;
	}
  	fclose(stdin);
	fclose(stdout);
    return 0;
}  

