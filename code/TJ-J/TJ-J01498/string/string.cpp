#include <bits/stdc++.h>
using namespace std;

int m[100005];
string f[10000000];
string hh[10000000];
int a[100005];
long long cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
     int n;
    cin>>n;
char gh;

int lei2=1;
    long long ans=0;
    int as=1;
    for (int i=1;i<=n;i++) 
    {
    	int lei=lei2;
    	cin>>m[i];
    	cin>>f[i];
    	for(int j=cnt+1;j<cnt+m[i];j++)
    	{
    	hh[j]=f[i];	
    	
		}
	cnt+=m[i];
	}
		int l2=1;
	int r2=cnt/2+1;
for(int i=1;i<=cnt;i++)
{
	
	if(hh[i]!=hh[r2+i])
	ans++;
}


cout<<ans;
return 0;
}
