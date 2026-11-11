#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[200005],ans,maxn;
bool flag1=true,flag2=true;
bool judge(long long x)
{
    long long id=1,num=1;
    while(num<=20)
    {
        if(id==x)return true;
        id*=2;
        num++;
    }
    return false;
}
void dfs(int num ,long long temp,int last)
{
    //cout<<num<<" "<<temp<<" "<<last<<endl;
    if(num>m)
    {
        ans=max(ans,temp);
    }
    for(int i=last+1;i<=n;i++)
    {
        if(i+(m-num)>n)break;
        if(!num)
        {
            dfs(1,a[i],i);
        }
        else dfs(num+1,temp&a[i],i);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(a[i],maxn);
        if(!judge(a[i]+1))flag1=false;
        if(a[i]!=i-1)flag2=false;
    }
    if(m==1)
    {
        cout<<maxn;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=(ans&a[i]);
        }
        cout<<ans;
    }
    else if(flag1)
    {
        sort(a+1,a+n+1);
        for(int i=n;i>=n-m+1;i--)
        {
            if(i==n)ans=a[i];
            else ans=(ans&a[i]);
        }
        cout<<ans;
    }
    else if(flag2&&judge(n))
    {
        cout<<n-1;
    }
    else
    {
        dfs(0,0,0);
        cout<<ans;
    }
    return 0;
}
//4 2
//3 15 12 12
//5 3
//31 3 1 15 7
