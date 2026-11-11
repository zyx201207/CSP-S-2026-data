#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a(500001);
vector<int> cnt3(300001);
vector<int> cnt2(300001);
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cnt2.clear();
        for(int j=i;j<=n;j++)
        {
            if(cnt2[a[j]]==0) cnt2[a[j]]++;
            else
            {
                for(int k=j-1;k>=i;k--)
                {
                    if(a[k]!=a[j]) cnt2[a[k]]--;
                    if(a[k]==a[j])
                    {
                        cnt2[a[k]]--;
                        break;
                    }
                }
                cnt2[a[j]]++;
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(cnt2[a[j]]!=0) cnt3[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt3[a[i]]<<' ';
    return 0;
}
