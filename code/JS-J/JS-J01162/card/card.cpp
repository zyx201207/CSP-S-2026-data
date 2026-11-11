#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,cnt = 0,ans[300005];
ll a[500005],q[500005];
void pop()
{
    q[cnt] = 0;
    cnt--;
}
ll top()
{
    return q[cnt];
}
void push(ll x)
{
    cnt++;
    q[cnt] = x;
}
bool empty()
{
    return q[1]==0&&q[0]==0;
}
bool sffind(ll x)
{
    for(int i = 1;i<=cnt;i++)
    {
        if(q[i]==x)
            return true;
    }
    return false;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
        scanf("%lld",&a[i]);
    if(m==1)
    {
        cout<<n<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = i;j<=n;j++)
        {
            if(sffind(a[j]))
            {
                while(top()!=a[j])
                    pop();
            }
            else
            {
                push(a[j]);
            }
        }
        while(!empty())
        {
            ans[top()]++;
            pop();
        }
    }
    for(int i = 1;i<=m;i++)
        printf("%d ",ans[i]);
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
