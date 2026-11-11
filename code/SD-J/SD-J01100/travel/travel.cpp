#include<bits/stdc++.h>
using namespace std ;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s , s2 ;//车厢号
	string a , a2 ;//座号 
	cin>>s>>a>>s2>>a2;
	//同一车厢 
	if(s==s2)
	cout<<1;
	else
	cout<<0;
	//         同一排 
	if(s==s2&&a[0]==a2[0]&&a[1]==a2[1])
	cout<<1;
	else
	cout<<0;
	//                                   同一侧        
	if(s==s2&&a[0]==a2[0]&&a[1]==a2[1]&&((a[2]>='D'&&a2[2]>='D')||(a[2]<'D'&&a2[2]<'D')))
	cout<<1;
	else
	cout<<0;
	//                                                                                    相邻      
	if(s==s2&&a[0]==a2[0]&&a[1]==a2[1]&&((a[2]>='D'&&a2[2]>='D')||(a[2]<'D'&&a2[2]<'D'))&&(max(a[2],a2[2])-min(a[2],a2[2])==1||a[2]>='D'&&a2[2]>='D'))
	cout<<1;
	else
	cout<<0;
	return 0 ;
}
