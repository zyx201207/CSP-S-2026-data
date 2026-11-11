#include<bits/stdc++.h>
using namespace std;
map<int,int>a;
int cnt[10000005],b[10000005];
stack<int>q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[b[j]]==1)
            {
                while(q.top()!=b[j] && !q.empty())
                {
                    a[q.top()]--;
                    q.pop();
                }
            }
            else{
                a[b[j]]++;
                q.push(b[j]);
            }
        }
        for(int j=1;j<=m;j++)
        {
            cnt[j]+=a[j];
            a[j]=0;
        }
        while(!q.empty())q.pop();

    }
    for(int i=1;i<=m;i++)
    {
        cout << cnt[i] << ' ';
    }
    return 0;
}
