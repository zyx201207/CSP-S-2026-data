#include<bits/stdc++.h>
using namespace std;

int a[200005];

 freopen("and.in","r",stdin);
 freopen("and.out","w",stdout);

bool cmp(int a,int b)
{

    return a>b;
}


int main()
{
    //cout<<(12&3);
    int n,m; scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        int p=a[i];
        for(int j=i+1;j<=i+m-1;j++)
        {
            p=(a[j]&p);
        }
        maxn=max(maxn,p);

    }
    cout<<maxn;
    return 0;
}
