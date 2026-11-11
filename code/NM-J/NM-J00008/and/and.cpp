#include<bits/stdc++.h>
using namespace std;
long long a[200010],ans=0,cnt=0;
bool f[200010];
int n,m,q,b;
int main()
{
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cnt=0;
    int v=1;
    for(int j=1;j<=n;j++)
    {
        f[j]=1;
        q++;
        if(q==m-1) b=j;
        if(q==m)
        {
            for(int k=v;k<=n;k++)
            {
                if(f[k]==1) cnt=cnt&a[k];
            }
	        cnt=0;
	        f[j]=0;
	        q--;
	        if(j>=n&&j-b<=2)
			{
				f[b]=0;
				v++;
				j=v-1;
				b=0;
				q=0;
			}
			else if(j>=n)
            {
                j=b;
                b=0;
                f[b]=0;
            }
		}
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
