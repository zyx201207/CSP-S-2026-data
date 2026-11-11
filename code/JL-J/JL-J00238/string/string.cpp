#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node
{
    char c;
    ll b;
};
int n;
ll sum;
node a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].b>>a[i].c;

    }
    int i=1;
    while(1)
    {
        if(i>=n)
        {
            break;
        }
        ll maxa,maxb;
        if(a[i].b>a[n].b)
        {
            maxa=i;
            maxb=n;
        }
        else
        {
            maxa=n;
            maxb=i;
        }
        if(a[i].c==a[n].c)
        {
            if(a[i].b==a[n].b)
            {
                i++;
                n--;
            }
            else
            {
                if(maxa==i)
                {
                    a[i].b-=a[n].b;
                    n--;
                }
                else
                {
                    a[n].b-=a[i].b;
                    i++;
                }
            }
        }
        else
        {
            ll qw=a[maxb].b;
            sum+=qw;
            if(a[i].b==a[n].b)
            {
                i++;
                n--;
            }
            else
            {
                if(maxa==i)
                {
                    a[i].b-=a[n].b;
                    n--;
                }
                else
                {
                    a[n].b-=a[i].b;
                    i++;
                }
            }
        }
        //cout<<sum<<" "<<i<<" "<<n<<endl;
    }
    cout<<sum;
    return 0;
}
