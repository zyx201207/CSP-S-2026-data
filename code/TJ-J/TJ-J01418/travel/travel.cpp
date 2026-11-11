#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool flag,flag1,flag2;
	flag=flag1=flag2=0;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1,flag=1;
	else cout<<0;
	int x=0,y=0;
	x=(b[0]-'0')*10+(b[1]-'0');
	y=(d[0]-'0')*10+(d[1]-'0');
	if(flag and x==y)cout<<1,flag1=1;
	else cout<<0;
	if(((b[2]>='A' and b[2]<='C' and d[2]>='A' and d[2]<='C') or (b[2]>='D' and b[2]<='F' and d[2]>='D' and d[2]<='F')) and flag and flag1)cout<<1,flag2=1;
	else cout<<0;
	if(flag and flag1 and flag2 and (((b[2]=='F' and d[2]=='D') or (b[2]=='D' and d[2]=='F')) or abs(int(b[2]-d[2]))<=1 ))cout<<1;
	else cout<<0;
	return 0;
}
/*
两张车票对应的座位是否在同一节车厢；
两张车票对应的座位是否在同一节车厢的同一排；
两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
两张车票对应的座位是否相邻
*/
// 2026/10/31 09:11 by :LAK 
