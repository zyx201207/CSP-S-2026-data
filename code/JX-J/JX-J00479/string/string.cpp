#include<bits/stdc++.h>
using namespace std;
struct Node{
    int len;
    long long l;
}x[200005];
long long sum,n,ans;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i].len>>c[i];
        if(i==1)
            x[i].l=1;
        else
            x[i].l=sum+1;
        sum+=x[i].len;
    }
    if(sum%2==0)
    {
        long long mid=sum/2,nowx1=1,nowl1=1,nowx2=n,nowl2=sum-x[n].len;
        for(int i=1;i<=mid;i++){
            if(nowl1+x[nowx1].len-1<i)
            {
                nowl1+=x[nowx1].len;
                nowx1++;
            }
            if(nowl2>sum-i)
            {
                nowx2--;
                nowl2-=x[nowx2].len;
            }
            if(c[nowx1]!=c[nowx2])
                ans++;
        }
    }
    else
    {
        long long mid=sum/2+1,nowx1=1,nowl1=1,nowx2=n,nowl2=sum-x[n].len;
        for(int i=1;i<mid;i++){
            if(nowl1+x[nowx1].len-1<i)
            {
                nowl1+=x[nowx1].len;
                nowx1++;
            }
            if(nowl2>sum-i)
            {
                nowx2--;
                nowl2-=x[nowx2].len;
            }
            if(c[nowx1]!=c[nowx2])
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
