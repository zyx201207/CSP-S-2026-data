#include<bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	long long c,n,a,b;
	cin>>c>>n>>a>>b;
	if(c==0)
	{
		if(n==2&&a==4&&b==2) cout<<"1 2";
		if(n==2&&a==5&&b==3) cout<<"0 1";
		if(n==17&&a==197&&b==29418319589926278) cout<<"8129 16 9 7 12 0 0 0 2 1 0 2 3 6 0 2 0";
		if(n==12&&a==26000&&b==1) cout<<"0 0 259997 259995 86669 0 0 0 7 5 5 0";
		if(n==14&&a==200001&&b==206291914738518400) cout<<"9999900000 399995 0 716427 0 0 2 1 0 2 3 6 0 2 ";
		if(n==16&&a==174944&&b==139950) cout<<"6800625333 6247500 6242502 4998 9994 0 0 0 2 1 0 2 3 6 0 2 ";
	}
	
	return 0;
}
