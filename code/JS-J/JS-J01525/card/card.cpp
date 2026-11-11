#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],ans[300300];
bool f[300300],iff[500500];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n;i>0;i--)
    {
        if(!f[a[i]])
        {
            ans[a[i]]+=i;
            f[a[i]]=1;
        }
        else
        {
            for(int j=i+1;a[i]!=a[j] || iff[j];j++)
            {
                iff[j]=1;
                if(f[a[j]])ans[a[j]]-=i;
                f[a[j]]=0;
            }
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
	return 0;
}
