//wangyinuo   xianfulunzhongxue   SN-J00671
#include<bits/stdc++.h>
using namespace std;
string l="";
int r;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		r+=a;
		char b;
		cin>>b;
		for(int j=1;j<=a;j++)
		{
			l+=b;
		}
	}
	
	
	return 0;
}