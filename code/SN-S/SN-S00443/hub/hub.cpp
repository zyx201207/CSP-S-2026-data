//SN-S00443 何昊雨铮 西安铁一中国际合作学校
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char cc;
	while(1){cc=getchar();if(cc=='-'||('0'<=cc&&cc<='9'))break;}
	int sum=0,flag=1;
	cc=='-'?flag=-1:sum=(cc^48);
	while(1){cc=getchar();if(cc<'0'||'9'<cc)break;sum=(sum<<1)+(sum<<3)+(cc^48);}
	return sum*flag;
}
inline void print(int x)
{
	if(!x)putchar('0');
	if(x<0){putchar('-');x=-x;}
	int cntt=0,numm[25];
	while(x){numm[++cntt]=x%10;x/=10;}
	for(int i=cntt;i>=1;i--)putchar('0'+numm[i]);
	putchar('\n');
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	return 0;
}


