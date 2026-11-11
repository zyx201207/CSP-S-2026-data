#include<bits/stdc++.h>
using namespace std;
struct Node
{
    long long  val;
    int num=0;
};
bool cmp(Node a,Node b)
{
    if(a.num==b.num)
    {
        return a.val>b.val;
    }
    return a.num>b.num;
}

Node a[200005];
long long num[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i].val);
        long long x=a[i].val;
        while(x)
        {
            x=x&(x-1);
            a[i].num++;
        }
    }
    sort(a+1,a+n+1, cmp);
    long long ans=a[1].val;
    for(int i=2; i<=m; i++)
    {
        ans=ans&a[i].val;
    }
    cout<<ans;
    return 0;
}



