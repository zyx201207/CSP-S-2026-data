#include <iostream>
#include <string>
using namespace std;
string s;
void pluss(int a,char ch)
{
	for(int i=1;i<=a;i++)
		s+=ch;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sl=0,sum=0;//sl:字符串长度 sum:修改数 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char ch;
		cin>>a>>ch;
		sl+=a;
		pluss(a,ch);
	}//输入
	for(int i=0;i<=(sl-1)/2;i++)
	{
		//cout<<s[i]<<' '<<s[sl-1-i]<<endl; 
		if(s[i]!=s[sl-1-i])
			sum++;
	} 
	cout<<sum;
	return 0;
}
