#include<bits/stdc++.h>
using namespace std;
long long n,m,a,cnt[100005];
queue<int>q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        q.push(a);
        cnt[a]++;
        if(cnt[a]>1)
        {
            q.pop();
            cnt[a]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }

    return 0;
}


