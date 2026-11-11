#include <iostream>
#include <string>
using namespace std;

int cnt;
int l;
int a[100001];
char b[100001];
int d[100000000000][2];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int c=0;
	cnt=0;
	cin>>l;
	int q=1;
	for(long long i=1;i<=l;i++)
	{
		cin>>a[i]>>b[i];
		c+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			d[q][1]=(int)(b[i]);
			q++;
		}
	}
	
	for(long long i=l;i>=1;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			d[q][2]=b[i];
			q--;
		}
	}
	for(long long i=1;i<=c;i++)
	{
		if(d[i][1]==d[i][2])
		{
			cnt+=0;
		}
		else
		{
			cnt+=1;
		}
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
