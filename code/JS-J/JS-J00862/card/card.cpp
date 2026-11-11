#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m; cin>>n>>m;
    int a[m+5];
    for(int i=0;i<m;i++) cin>>a[i];
    int cnt[m+5]={0};
    for(int i=0;i<n;i++)
    {
        int start=i; int mh=m;
        int out[m+5]={0};int mo=0;
        while(mh!=0)
        {
            start++;
            for(int i=0;i<a[start];i++)
            {
                if(out[i]==a[start])
                    mo=i;
            }
            out[mo++]=a[start];
        }
        for(int i=0;i<mo;i++)
            cnt[out[i]]++;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
