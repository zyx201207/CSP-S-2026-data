#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    long long cnt=0;
    int h=1;
    int t=n;
    int hc=a[1];
    int tc=a[n];
    while(h<t)
    {
        if(hc<tc)
        {
            if(c[h]!=c[t])
            {
                cnt += hc;
            }
            tc -= hc;
            h++;
            hc = a[h];
        }
        else if(hc>tc)
        {
            if(c[h]!=c[t])
            {
                cnt += tc;
            }
            hc -= tc;
            t--;
            tc = a[t];
        }
        else
        {
            if(c[h]!=c[t])
            {
                cnt += hc;
            }
            t--;
            h++;
            hc = a[h];
            tc = a[t];
        }
    }
    cout<<cnt;
    return 0;
}
