#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("travel.in","r",travel.in);
	//freopon("travel.out","w",travel.out);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<< "1";
	else cout<<"0";
	int r=b%10;
	int x=d%10;
	if(r==x) cout<<"1";
	else cout<< "0";
	if(r==x)cout<< "1";
	else cout<<"0";
	int q=b/10;
	int p=d/10;
	if(p+1==q||p-1==q)cout<<"1";
	else cout<< "0";
	return 0;
}
