#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    int a[n+2]={},sum[m+2]={};
    vector<int> gc(1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            gc.push_back(a[j]);
            for(int c=j-i;c>=1;c--)
            {
                if(gc[c]==gc[j])
                {
                    for(int t=j;t>=c;t--)
                        gc.pop_back();
                    gc.push_back(a[j]);
                }
            }
        }
        for(int j=gc.size()-1;j>=1;j--)
        {
            sum[gc[j]]++;
            gc.pop_back();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout << sum[i] << " ";
    }
    return 0;
}
