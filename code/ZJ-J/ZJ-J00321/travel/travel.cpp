#include<cstdio>
#include<cmath>
//RP++
//Let me AK CSP-J pls CCF!!!
int c1,c2;
char s1[10],s2[10];
int s1_,s2_,st1,st2;
bool f=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %s %d %s",&c1,s1+1,&c2,s2+1);
	s1_=(s1[1]-'0')*10+s1[2]-'0';
	s2_=(s2[1]-'0')*10+s2[2]-'0';
	st1=s1[3]-'A'+1;
	st2=s2[3]-'A'+1;
	f&=(c1==c2);
	if(f)putchar('1');
	else putchar('0');
	f&=(s1_==s2_);
	if(f)putchar('1');
	else putchar('0');
	f&=(st1<=3&&st2<=3||st1>=4&&st2>=4);
	if(f)putchar('1');
	else putchar('0');
	if(f&&(st1<=3&&abs(st1-st2)==1||(st1>3)))putchar('1');
	else putchar('0');
	return 0;
}
/*
//freopen
//freopen
默写 你看到的我 我要上人类迷惑行为大赏 

背起了行囊，离开家的那一刻，
我知道现实生活，有太多特别的特。
假如你又看到我，请给我一个拥抱。
我多愁伤感，但也热情奔放洒脱！ 

匆忙的世界，来不及问为什么，
我知道漂泊的人，心中都有一团火。
假如你又看到我，请不要太过冷漠。
我偶尔沉默，但也勇敢执着！ 

你看到的我，你看到的我，
是哪一种颜色，悲伤或快乐。
也许老了一点，眼神也不再那么清澈，
热血依旧沸腾着我的脉搏！ 

你看到的我，你看到的我，
是哪一种性格，开朗或慢热。
像勇敢的鱼鹰，不怕风雨不怕困难挫折 ，
要飞就要飞出天空海阔，我就是我！ 
*/
