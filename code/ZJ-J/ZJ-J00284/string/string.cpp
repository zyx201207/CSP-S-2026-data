#include<bits/stdc++.h>
using namespace std;
char my_ch[3000001];
long long my_count[3000001],my_ccc=0;
long long my_num,iii,jjj,my_xyz;
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>my_num;
	iii=1;
	jjj=my_num;
	for(int my_i=1;my_i<=my_num;my_i++)
	{
		cin>>my_count[my_i]>>my_ch[my_i];
	}
	while(iii<jjj)
	{
		my_xyz=min(my_count[jjj],my_count[iii]);
		if(my_ch[jjj]!=my_ch[iii])
		{
			my_ccc+=my_xyz;
		}
		my_count[jjj]-=my_xyz;
		my_count[iii]-=my_xyz;
		if(my_count[jjj]==0)jjj--;
		if(my_count[iii]==0)iii++;
	}
	cout<<my_ccc;
	return 0;
}
