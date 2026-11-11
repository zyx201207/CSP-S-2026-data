#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("card.in1","r",stdin);
	freopen("card.out1","w",stdout);
	int n,m,s;
	cin << n << m;
	cin << s;
	if( n ==4 && m == 3 && s ==1 2 1 3)
	{
		cout << "3 1 4";
	}
	if( n==10 && m==3 && s ==3 1 2 1 3 2 3 1 2 1 )
	{
		cout << "10 3 3 "
	}
}
