#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[50005];
int b[30005];
stack <int> s;
void tong(stack <int> s1)
{
    bool c[30005];
    memset(b,0,sizeof b);
    while(!s.empty())
    {
        if(c[s1.top()] == 0) b[s.top()]++;
        s1.pop();
    }
}
int sfind(int k)
{
    int jsq = 0;
    stack <int> s1 = s;
    while(!s1.empty())
    {
        jsq++;
        if(s1.top() == k) return jsq;
        s1.pop();
    }
    return -1;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = i;j <= m;j++)
        {
            int c = sfind(a[i]);
            if(c != -1)
            {
                for(int i = 1;i <= c;i++)
                {
                    s.pop();
                }
            }
            s.push(a[j]);
        }
        tong(s);
    }
    for(int i = 1;i <= n;i++)
    {
        printf("%d\n",b[i]);
    }
    return 0;
}
