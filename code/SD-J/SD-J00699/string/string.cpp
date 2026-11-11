#include <bits/stdc++.h>
using namespace std;
string ss;
long long hui()
{
	int nn=ss.size()-1;
    int ii=0;
    long long ans=0;
    while(ii<=nn)
    {
    	if(ss[ii]!=ss[nn]) ans++;
    	ii++,nn--;
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int nn;
	cin>>nn;
	while(nn--)
	{
		int xx;
		char aa;
		cin>>xx>>aa;
		for(int i=1;i<=xx;i++)
		{
			ss+=aa;
		}
	}
	long long ans=hui();
	cout<<ans;
}
