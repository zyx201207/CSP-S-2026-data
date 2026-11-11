#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
int main()
{
    freopen("crystsl.in","r",stdin);
    freopen("crystsl.out","w",stdout);
    int m,n;
    cin >> n >> m;
    long long mx = -1000000;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++)
    {
        long long KY = m,new_mx = 1;
        for(int j = i-1;j>=1;j--)
        {
            int YY = abs(a[i]-a[j]);
            if(YY<=KY)
            {
                KY-=YY;
                new_mx++;
            }
            else
            {
                break;
            }
        }
        if(new_mx>mx)
        {
            mx = new_mx;
        }
    }
    cout << mx;
    return 0;
}
