#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b[n+5];
    int cnt=1;
    queue<int>q;
    int x[300005]={};
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(x[a]!=0)
        {
            while(q.front()!=a)
            {
                q.pop();
                cnt--;
            }
            q.pop();
            cnt--;
        }
        q.push(a);
        cnt++;
        x[a]++;
    }
    for(int i=1;i<=cnt;i++)
    {
        b[i]=q.front();
        q.pop();
    }
    for(int i=cnt;i>=1;i--)
    {
        cout<<b[i];
    }
    return 0;
}
