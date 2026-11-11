#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n,cnt=0;;
	cin>>n;
	char cha;
	bool b=true;
	vector<long long int> v(n+1);
	vector<char> ch(n+1);
	for(long long int i=1;i<=n;i++)
	{
		cin>>v[i]>>ch[i];
		if(ch[i]!=cha)
		{
			b=false;
		}
		cha=ch[1];
	}
	if(b==false)
	{
		char ch1=ch[1];
		char ch2=ch[n];
		long long int v1=v[1];
		long long int v2=v[n];
		if(ch1==ch2)
		{
			for(long long int i=2;i<=n/2;i++)
			{
				long long int j=n+1-i;
				if(ch[i]==ch1&&ch[j]==ch2)
				{
					v1+=v[i];
					v2+=v[j];
				}
				else
				{
					if(ch[i]==ch[j])
					{
						cnt+=max(v1,v2)-min(v1,v2);
						ch1=ch[i];
						ch2=ch[j];
						v1=v[i];
						v2=v[j];
					}
				}
			}
			if(n%2!=0)
			{
				if(ch1!=ch[n/2+1]&&ch1==ch2)
				{
					cnt+=max(v1,v2)-min(v1,v2);	
				}	
			}	
		}
	}
	if(b==false)
	{
		for(long long int i=1;i<=n/2;i++)
		{
			long long int j=n-i+1;
			if(ch[i]!=ch[j])
			{
				cnt+=max(v[i],v[j]);
			}
		}
	}
	cout<<cnt;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
