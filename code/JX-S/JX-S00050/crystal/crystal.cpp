#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,cnt = 0,sum = 0;
    cin>>n>>m;
    long long a[500005];
    long long b[500005];
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        cnt+=a[i];
    }
    sort(a+1,a+1+n);
    cnt = cnt/n;
    for(int i = 1;i<=n;i++)
    {
        b[i] = abs(a[i] - cnt);
    }
    sort(b+1,b+1+n);
    for(int i = 1;i<=n;i++)
    {
        if(m - b[i]>=0)
        {
            m-=b[i];
            sum++;
        }
        else{
            cout<<sum;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
