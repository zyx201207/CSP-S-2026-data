#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i = 1;i <= n;i ++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i = 0;i < n;i ++)
    {
        int c[300005] = {0};
        stack<long long> q;
        for(int j = i + 1;j <= n;j ++)
        {
            if(c[a[j]] == 0)
            {
                q.push(a[j]);
                c[a[j]] ++;
            }
            else
            {
                while(q.top() != a[j])
                {
                    int num = q.top();
                    q.pop();
                    c[num] --;
                }
            }
        }
        for(int j = 1;j <= m;j ++)
        {
            b[j] += c[j];
        }
    }
    for(int i = 1;i <= m;i ++)
    {
        printf("%lld ",b[i]);
    }
    return 0;
}
