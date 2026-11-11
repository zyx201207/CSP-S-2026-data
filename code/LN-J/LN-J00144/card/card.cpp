#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],last[300001],ans[300001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        last[a[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        int now=i;
        while(1)
        {
            ans[a[now]]++;
            now=last[a[now]]+1;
            if(now==n)
            {
                break;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
