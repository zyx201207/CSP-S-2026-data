#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,s=0;
    long long a[100006]={0};
    char c[100006];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i] >> c[i];
    long long l=0,r=n-1,g=0,k=0;
    while(l<r)
    {
        if(k>=a[l])
        {
            k -= a[l];
            l++;
        }
        if(g>=a[r])
        {
            g -= a[r];
            r--;
        }
        if(c[l]==c[r])
        {
            if(a[r]-g>a[l]-k)
            {
                g += a[r]-g-(a[l]-k);
                l++;
                k = 0;
            }
            else if(a[r]-g<a[l]-k)
            {
                k += a[l]-k-(a[r]-g);
                r--;
                g = 0;
            }
            else
            {
                g = 0;
                k = 0;
                r--;
                l++;
            }
        }
        else
        {
            if(a[r]-g>a[l]-k)
            {
                s += a[l]-k;
                g += a[r]-g-(a[l]-k);
                l++;
                k = 0;
            }
            else if(a[r]-g<a[l]-k)
            {
                s += a[r]-g;
                k += a[l]-k-(a[r]-g);
                r--;
                g = 0;
            }
            else
            {
                s += a[r]-g;
                g = 0;
                k = 0;
                r--;
                l++;
            }
        }
    }
    cout << s << '\n';
    return 0;
}
