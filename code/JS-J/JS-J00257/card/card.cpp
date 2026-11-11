#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m, lent;
    cin>>n>>m;
    int s[n], al[m+1]={0}, ex[n], flag[m+1]={0};
    for (int i=0;i<n;i++) cin>>s[i];
    for (int i=0;i<n;i++)
    {
        memset(ex, 0, sizeof(ex));
        lent=0;
        for (int j=i;j<n;j++)
        {
            for (int k=0;k<lent;k++) if (ex[k]==s[j])
            {
                lent=k;
                break;
            }
            ex[lent]=s[j];
            lent++;
        }
        memset(flag, 0, sizeof(flag));
        for (int j=0;j<lent;j++) flag[ex[j]]=1;
        for (int j=1;j<=m;j++) al[j] += flag[j];
    }
    for (int i=1;i<=m;i++) cout<<al[i]<<" ";
    return 0;
}
