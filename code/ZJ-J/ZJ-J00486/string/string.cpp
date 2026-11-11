#include<bits/stdc++.h>
using namespace std;

const int N=200010; 
int n;
unsigned long long ans;

struct zfc
{
	int a;
	char c;
}s[N];

bool cha(int one,int two,bool add)
{
	if(s[one].a>=s[two].a)
	{
		if(add)ans+=s[two].a;
		s[one].a-=s[two].a;
		s[two].a=0;
		return false;
	}
	if(s[two].a>s[one].a)
	{
		if(add)ans+=s[one].a;
		s[two].a-=s[one].a;
		s[one].a=0;
		return true;
	}
}

int main()
{
	ifstream fin("string.in");
	ofstream fout("string.out");
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		fin>>s[i].a>>s[i].c;
	}
	int j=n;
	for(int i=1;i<=n&&j>=1;)
	{
		if(i==j)break;
		if(i>j)break;
		if(s[i].c==s[j].c)
		{
			if(cha(i,j,false))
				i++;
			else
				j--;
		}
		else
		{
			if(cha(i,j,true))
				i++;
			else
				j--;
		}
	}
	fout<<ans;
} 
