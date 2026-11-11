/*
有n颗能量水晶，其中第 i 颗的能量值为整数 a 中的第 i 项的值
合成一颗大水晶，用于合成的水晶必须具有相同的能量值
参与合成的水晶尽可能多
他可以进行至多 m 次操作
每次操作可以任选一颗水晶，将其能量值增加 1
同一颗水晶可以被重复选择
进行至多 m 次操作后，他最多能用多少颗 能量水晶合成一颗大水晶
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios :: sync_wich_stdio(0);
	cin.tie(0);
	
	long long  n,m;		//n:能量水晶的数量 m:最多可以进行的操作次数
	cin>>n>>m;
	int a[500005];	//a:储存水晶 
	
	for(int i=1;i<=n;i++)	//输入a(水晶能量)
	{	 
		cin>>a[i];
	}
	
	return 0;
} 
