#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=10*x+(ch-'0'),ch=getchar();
    return x*f;
}
struct node
{
    long long len;
    char c;
}a[200001];
int n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)a[i].len=read(),a[i].c=getchar();
    int l=1,r=n;
    long long ans=0;
    while(l<r)
    {
        if(a[l].c==a[r].c)
        {
            long long minn=min(a[l].len,a[r].len);
            a[l].len-=minn;
            a[r].len-=minn;
            if(!a[l].len)l++;
            if(!a[r].len)r--;
        }
        else
        {
            if(a[l].len<=a[r].len)
            {
                ans+=a[l].len;
                a[l].c=a[r].c;
            }
            else
            {
                ans+=a[r].len;
                a[r].c=a[l].c;
            }
        }
    }
    cout<<ans;
    return 0;
}
