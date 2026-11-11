#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int l,r;
    char val;
};
node a[200005];
int n;
int32_t main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char y;
        cin>>x>>y;
        a[i].l=a[i-1].r+1;
        a[i].r=a[i].l+x-1;
        a[i].val=y;
    }
    int qujian1,qujian2,pos1,pos2;
    char nowval1,nowval2;
    qujian1=1;
    qujian2=n;
    pos1=1;
    pos2=a[qujian2].r;
    nowval1=a[qujian1].val;
    nowval2=a[qujian2].val;
    int ans=0;
    while(qujian1!=qujian2 && qujian1<qujian2)
    {
        int rest1=a[qujian1].r-pos1+1;
        int rest2=pos2-a[qujian2].l+1;
        if(rest1<rest2)
        {
            if(nowval1!=nowval2)
            {
                ans+=rest1;
            }
            qujian1++;
            pos1=a[qujian1].l;
            nowval1=a[qujian1].val;
            pos2-=rest1;
        }
        else if(rest1>rest2)
        {
            if(nowval1!=nowval2)
            {
                ans+=rest2;
            }
            qujian2--;
            pos2=a[qujian2].r;
            nowval2=a[qujian2].val;
            pos1+=rest2;
        }
        else
        {
            if(nowval1!=nowval2)
            {
                ans+=rest1;
            }
            qujian1++;
            qujian2--;
            nowval1=a[qujian1].val;
            nowval2=a[qujian2].val;
            pos1=a[qujian1].l;
            pos2=a[qujian2].r;
        }
    }
    cout<<ans;
    return 0;
}
