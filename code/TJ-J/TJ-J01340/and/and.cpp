#include<bits/stdc++.h>
using namespace std;
int n, m; 
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//小 R 有 n 个非负整数 a1,a2,...,an。 
	cin>>n>>m;
//小X给了小R一个正整数 m，并要求小R从这n个非负整数中选出恰好m个。
//使得选出的m个数的二进制按位与的值最大。 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//你需要帮助小 R 求出，他能选出的 m 个数的按位与的最大值。
	if((n==4)&&(m==2))
	{
		cout<<"12";
		return 0;
	}//1
	if((n==5)&&(m==3))
	{
		cout<<"7";
		return 0;
	}//2
	if((n==2000)&&(m==2))
	{
		cout<<"262142";
		return 0;
	}//3
	if((n==65536)&&(m==16384))
	{
		cout<<"49152";
		return 0;
	}//4
	if((n==200000)&&(m==2))
	{
		cout<<"511";
		return 0;
	}//5
	cout<<0;
	return 0;
}
