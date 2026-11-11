#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,maxn,sum;
unsigned long long a[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (m==2)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<i;j++)
            {
                sum=max(sum,a[i]&a[j]);
            }
        }
    }
    else{

        sort(a+1,a+n+1,greater<long long>());
        sum=a[1];
        for (int i=2;i<=m;i++)
        {
            sum&=a[i];
        }
    }
    cout<<sum;
    return 0;
}
