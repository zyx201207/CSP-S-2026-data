#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a[500010],cnt[500010],m,cnt1[500010];
    queue<int> q;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int k=1;k<=n;k++)
    {
        while(!(q.empty()))
        {
            q.pop();
        }
        for(int i=1;i<=n;i++)
        {
            q.push(a[i]);
            cnt[a[i]]++;
            if(cnt[a[i]]>1)
            {
                while(1)
                {

                    q.pop();
                    if(q.front()==a[i])
                    {
                        break;
                    }
                }
            }
        }
        long long len=q.size();
        for(int i=i;i<len;i++)
        {
            cnt1[q.front()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt1[i]<<" ";
    }
    return 0;
}
