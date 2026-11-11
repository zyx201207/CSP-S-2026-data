# include<cstdio>
# include<iostream>
# include<algorithm>
using namespace std;
int n,maxn = 1;
long long m,a[500005],s[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++)
    {
        s[i] = s[i-1]+a[i];
    }
    for(int i = n;i>=maxn;i--)
    {
        for(int j = i;j>=1;j--)
        {
            if(a[i]*1ll*(i-j+1)-(s[i]-s[j-1])>m)break;
            //cout << i << " " << j << endl;
            maxn = max(maxn,i-j+1);
        }
    }
    cout << maxn;
    return 0;
}
