//SN-J00835 把小煜 西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,s1,s2;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	for(int i=0;i<2;i++) if(s1[i]!=s2[i])
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	char a=s1[2],b=s2[2];
	if((a<='C' && b<='C')||(a>'C' && b>'C'))
	{
		cout<<"1";
		if((a<='C' && b<='C'))
		{
			if(abs((int)(b-a))==1) cout<<"1";
			else cout<<"0";
		}
		else cout<<"1";
	}
	else cout<<"00";
	return 0;
}
