#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = (int)(2e5+10);
int a[N];
char c[N];

int n;
int ret=0;

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i]>>c[i];

    int l=0,r=n-1;
     while(l<=r)
    {
        if(a[l] <= a[r])
        {
            if(c[l]!=c[r])ret += a[l];
            //cout<<ret<<endl;
            a[r] -= a[l];
            //if(l+1>=r)
            //{
            //    printf("%lld", ret);
            //    break;
            //}
            l++;
        }
        else
        {
            if(c[l] != c[r])ret += a[r];
               //         cout<<ret<<endl;
            a[l] -= a[r];
            //if(r-1<=l)
            //{
            //    printf("%lld", ret);
            //    break;
            //}
            r--;
        }

    }
    printf("%lld", ret);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
