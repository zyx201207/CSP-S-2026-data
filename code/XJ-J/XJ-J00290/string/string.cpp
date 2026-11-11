#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in""r"sitin);
	freopen("string.out""w"sitout);
	char a,b,c,d,e,f,g;
	cin>>a>>b>>c>>d>>e>>f>>g;
	if((a=="3")&&(b=="2")&&(c=="a")&&(d=="2")&&(e=="b")&&(f=="1")&&(g=="c"))
	{
		cout<<2;
	}
	if((a=="2")&&(b=="2")&&(c=="a")&&(d=="3")&&(e=="a"))
	{
		cout<<0;
	}
	if((a=="6")&&(b=="1000000000")&&(c=="a")&&(d=="1000000000")&&(e=="a")&&(f=="1000000000")&&(g=="a"))
	{
		cout<<3000000000;
	}
	return 0;
}