#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
map<char,bool>mp;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['E']=0;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&mp[b[2]]==mp[d[2]]) cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&mp[b[2]]==mp[d[2]])
	{
		if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')) cout<<0;
		else cout<<1;
	}
	else cout<<0;
	return 0;
}
/*
foropen
feropen
froopen
*/
/*
好无聊，玩飞花令吧。
迟日江山丽，春风花草香。
夜来风雨声，花落知多少。
感时花溅泪，恨别鸟惊心。 
借问酒家何处有，牧童遥指杏花村。 
采得百花成蜜后，为谁辛苦为谁甜。 
落红不是无情物，化作春泥更护花。 
桃花一簇开无主，可爱深红爱浅红。 
花谢花飞花满天，红绡香断有谁怜。 
梅子金黄杏子肥，麦花雪白菜花稀。 
故人西辞黄鹤楼，烟花三月下扬州。 
春风得意马蹄疾，一日看尽长安花。 
乱花渐欲迷人眼，浅草才能没马蹄。 
~~一花一叶一菩提~~ 
*/ 
