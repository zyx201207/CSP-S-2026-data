#include<bits/stdc++.h>
using namespace std;
struct p
{
    long long x;
    char c;
};
int n;
p a[200005];
long long sum=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].c;
    }
    long long l=1,r=n;
    while(l<=r)
    {
        if(a[l].c==a[r].c)
        {
            if(a[l].x<=a[r].x)
            {
                a[r].x-=a[l].x;
                a[l].x=0;
                l++;
            }
            else
            {
                a[l].x-=a[r].x;
                a[r].x=0;
                r--;
            }
        }
        else
        {
            if(a[l].x<=a[r].x)
            {
                sum+=a[l].x;
                a[r].x-=a[l].x;
                a[l].x=0;
                l++;
            }
            else
            {
                sum+=a[r].x;
                a[l].x-=a[r].x;
                a[r].x=0;
                r--;
            }
        }
    }
    cout<<sum;
    return 0;
}
