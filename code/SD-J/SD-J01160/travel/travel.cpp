#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2);//是否在同一节车厢 
	string p1="",p2="";
	p1+=s1[0];
	p1+=s1[1];
	p2+=s2[0];
	p2+=s2[1];
	cout<<((c1==c2)&&(p1==p2));//是否在同一节车厢 同一排 
	char l1=s1[2],l2=s2[2];
	cout<<((c1==c2)&&(p1==p2)&&((l1<='C'&&l2<='C')||(l1>='D'&&l2>='D')));//是否在同一节车厢 同一排 同一侧
	if(c1!=c2) cout<<0;
	else if(p1!=p2) cout<<0;
	else
	{
		if(l1>l2) swap(l1,l2);//保证l1<l2 
		//cout<<endl<<l2<<endl;
		if(l2-l1==1)
		{
			if(l2!='D'&&l1!='C') cout<<1;
			else cout<<0;
		 } 
		else cout<<0;
	 } 
	return 0;//02 01A 02 01B
}
