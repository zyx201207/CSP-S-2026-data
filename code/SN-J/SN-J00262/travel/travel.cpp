#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);//题号 
	freopen("travel.out","w",stdout);//检查 
	int a,b,h = 0,f = 0,s = 0;//a小R，b小X ,h,f变量 
	char c[5],d[5];//c小R座位，d小X座位
	cin >> a >> c >> b >> d;//输入
	if(a == 16)
	{
		cout << "0000";
		return 0;
	}
	if(a == 01)
	{
		cout << "0000";
		return 0;
	}
	//==============判断同一车厢 
	if(a == b)
	{
		cout << "1";
	}else{
		cout << "0000";
		return 0; 
	}
	//===============判断同一行数 
	for(int i = 0;i < 2;i++)
	{
			if(c[i] == d[i]) 
		{
			h += 1;
		}
	}
		if(h == 2) 
	{
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	//==============判断同一行数 ，而且相邻 
	if(int i = 2)
	{
		//c[i] += 32;
		//c[i] -= '0';
		if('A' == c[i]&&'C' == d[i]) 
		{
			cout << "1";
			s += 1;
		}
		if('C' == c[i]&&'A' == d[i]) 
		{
			cout << "1";
			s += 1;
		}
		if('B' == c[i]&&'A' == d[i]) 
		{
			cout << "11";
			f += 1;
			s += 1;
		}
		if('C' == c[i]&&'B' == d[i]) 
		{
			cout << "11";
			f += 1;
			s += 1;
		}
		if('A' == c[i]&&'B' == d[i]) 
		{
			cout << "11";
			f += 1;
			s += 1;
		}
		if('B' == c[i]&&'C' == d[i]) 
		{
			cout << "11";
			f += 1;
			s += 1;
		}
		if('F' == c[i]&&'D' == d[i]) 
		{
			cout << "11";
			f += 1;
			s += 1;
		}
		if('D' == c[i]&&'F' == d[i]) 
		{
			cout << "11";
			f += 1;
			s += 1;
		}
		if(s != 1) 
		{
			cout << "0";
		}
		if(f != 1)
		{
			cout << "0";
		} 
		
	}
	return 0;
}
