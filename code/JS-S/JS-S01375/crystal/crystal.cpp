#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{

    int f=1,x=0;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return f*x;
}
const int MAXN=5e5+9;
int n,a[MAXN],m;
queue<int>q;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();int k=0,maxn=0,sum=0,ans=0;
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    maxn=a[1];
    for(int i=1;i<=n;i++)
    {
        sum+=(a[i]-maxn)*k;
        maxn=a[i];
        k++;
        q.push(a[i]);
        while(sum>m)
        {
            k--;
            int x=q.front();
            sum-=(maxn-x);
            q.pop();
        }
        ans=max(ans,k);
        //cout<<i<<" "<<k<<" "<<sum<<" "<<maxn<<endl;
    }
    cout<<ans;
    return 0;
}
