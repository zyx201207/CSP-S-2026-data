#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	if(s1[0]==s2[0]&&c1[0]==c2[0]){
		cout<<"1";
	}
	//cout<<c1<<s1<<c2<<s2;
	return 0;
}
