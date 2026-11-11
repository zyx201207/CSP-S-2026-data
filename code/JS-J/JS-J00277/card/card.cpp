//16fen
#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],t[300005],bot[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        t[a[i]]++;
    }
    int max_num=0;
    for(int i=1;i<=n;i++)
        max_num=max(max_num,t[a[i]]);
    for(int i=1;i<=n;i++)
    {
        if(t[a[i]]!=0&&bot[a[i]]==0)
        {
            cout<<max_num<<' ';
            bot[a[i]]=1;
        }

    }
    return 0;
}
