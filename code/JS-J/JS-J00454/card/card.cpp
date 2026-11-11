#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool b[300005];
stack<int> cards;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]])
            {

                while(cards.top()!=a[j])
                {
                    b[cards.top()]=0;
                    cards.pop();
                }

            }
            else
            {
                cards.push(a[j]);
                b[a[j]]=true;
            }
        }
        while(!cards.empty())
        {
            ans[cards.top()]++;
            cards.pop();
        }
        for(int j=1;j<=m;j++)
        {
            b[j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
