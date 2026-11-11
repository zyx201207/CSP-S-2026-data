#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005],q[500005],r,ans[300005],bj[300005][2];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int j=1;j<=n;j++)
    {
		cin>>a[j];
	}
	//cout<<1;
    int t=1;r=1;r=0;
    while(t<=n)
    {
        r=0;r=0;
        memset(bj,0,sizeof(bj));
        memset(q,0,sizeof(q));
        for(int i=t;i<=n;i++)
        {
            if(bj[a[i]][0]==0)
            {
                r++;
                bj[a[i]][0]=1;
                bj[a[i]][1]=r;
                q[r]=a[i];
            }
            else
            {
                int tt=r;
                r=bj[a[i]][1];
                for(int j=r+1;j<=tt;j++)
                {
                    bj[q[j]][0]=0;
                    bj[q[j]][1]=0;
                    q[j]=0;
                }
            }
            //for(int i=1;i<=n;i++)cout<<q[i]<<" ";
            //cout<<r<<endl;
        }
        for(int i=1;i<=r;i++)
        {
            ans[q[i]]++;
        }
        t++;
    }
    for(int i=1;i<=m;i++)
    {
        if(i!=1)cout<<" ";
        cout<<ans[i];
    }
    return 0;
}
