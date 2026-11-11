#include<bits/stdc++.h>
using namespace std;
const int M=10005;
int a[M];
int main()
{
	string ans;
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int maxn=-1;
	for(int i=n;i>0;i--)
	{
		int cnt;
        for(int j=0;j<m;j++)
		{
	     cnt=a[i+j]^a[i+j+1];
		}	
		if(cnt>maxn)
	    {
	    	maxn=cnt;
		}	
	}
	cout<<maxn<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
