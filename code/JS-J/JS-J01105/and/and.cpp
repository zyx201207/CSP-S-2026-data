#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000];

int maxans=0;
void dfs(int ith,int sum,int cnt)
{
    if((sum<=maxans&&sum!=-1)||cnt>m)
        return ;
    if(cnt==m)
        maxans=max(maxans,max(sum,0));
    if(ith==n) return ;
    dfs(ith+1,sum,cnt);
    if(sum==-1)
        dfs(ith+1,a[ith],cnt+1);
    else
        dfs(ith+1,sum&a[ith],cnt+1);
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n<=20)
    {
        dfs(0,-1,0);
        cout<<maxans<<endl;
        return 0;
    }
    if(m==1)
    {
        cout<<*max_element(a,a+n)<<endl;
        return 0;
    }
    if(m==2)
    {
        int maxans=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                maxans=max(a[i]&a[j],maxans);
        cout<<maxans<<endl;
        return 0;
    }
    if(m==n)
    {
        int ans=a[0];
        for(int i=1;i<n;i++)
            ans&=a[i];
        cout<<ans<<endl;
        return 0;
    }
 /*   if(m==n-1)
    {
        int bit[32],nn=0;
        memset(bis,0,sizeof(bit));
        for(int i=0;i<n;i++)
        {
            int x=a[i],cnt=0;
            while(x>0)
            {
                if(x%2==0)
                    bit[cnt]++;
                x/=2;
                cnt++;
            }
            nn=max(nn,cnt);
        }
        for(int i=0;i<n;i++)
        {
            int x=a[i],cnt=0;
            while(x>0)
            {
                if(x%2==0)
                    bit[cnt]--;
                x/=2;
                cnt++;
            }
            for(int i=0;i<nn;i++)
                if(bit[i]==0)

       }
    } */
    return 0;
}
