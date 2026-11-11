//孟梓瑜 SN-J00834 西安市铁一中学 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	int c_1,c_2,s_1p,s_1l,s_2p,s_2l;
	string s_1,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	s_1p=(int)(s_1[0]-'0')*10+(int)(s_1[1]-'0');
	s_2p=(int)(s_2[0]-'0')*10+(int)(s_2[1]-'0');
	s_1l=(int)(s_1[2]-'A'+1);
	s_2l=(int)(s_2[2]-'A'+1);
	
//	cout<<c_1<<" "<<s_1p<<" "<<s_1l<<"\n";
//	cout<<c_2<<" "<<s_2p<<" "<<s_2l<<"\n";
	
	if(c_1!=c_2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s_1p!=s_2p)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(!((s_1l<=3)&&(s_2l<=3)||(s_1l>3)&&(s_2l>3)))	
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(s_1l-s_2l)!=1)
	{
		cout<<0;
		return 0;
	}
	cout<<1;
	
	return 0;
}
