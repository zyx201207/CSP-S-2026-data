#include<bits/stdc++.h>
using namespace std;
long long s[10000],m;
long long p[10000][10000],zans=0;
bool tmp(long long x,long long y)
{
    return x<y;
}
long long po(long long n,long long m,long long c)
{
    for(long long i = 1;i <= n;i++)
    {
        if(m<0)
        {
            cout << i-1;
            break;
        }
        m-=i*c;
    }
    return 0;
}
int main()
{
     freopen("crystal.in","r",stdin);
     freopen("crysral.out","w",stdout);
    long long n;
    bool ai=1;
    cin >> n >> m;
    for(long long i = 1;i <= n;i++)
    {
        cin >> s[i];
        long long cha,chats;
        cha=s[i]-s[i-1];
        chats=s[i-1]-s[i-2];
        if(i>2&&cha!=chats)
        {
            ai=0;
        }
    }
    if(ai)
    {
        po(n,m,s[2]-s[1]);
        return 0;
    }
    sort(s+1,s+n+1,tmp);
    for(int i =1;i <= n;i++)
    {
        p[i][i]=0;
    }
    for(long long i = 2;i <= n;i++)
    {

        for(long long j = i;j <= n;j++)
        {
            long long l,r,mid,sum,ans;
            l=j-i+1;
            r=i;
            mid=(r+l)/2;
            sum=mid-l+1;
            ans=sum*(s[r]-s[mid]);
            if(ans<0)
            {
                ans=-ans;
            }
            p[l][r]=p[l][mid]+p[mid+1][r]+ans;
            if(p[l][r]<=m)
            {
                zans=max(zans,i);
            }
        }
    }
    cout << zans;
    return 0;
}
