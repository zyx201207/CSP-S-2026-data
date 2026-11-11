#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n+1];
    char c[n+1];
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int tjs=1,wjs=n;
    for(int i=1;i<=n;i++)
    {
        if(wjs<tjs)break;
        if(c[tjs]==c[wjs])
        {
            if(a[tjs]>a[wjs])
            {
                a[tjs]-=a[wjs];
                wjs--;
            }
            else if(a[tjs]<a[wjs])
            {
                a[wjs]-=a[tjs];
                tjs++;
            }
            else
            {
                wjs--;
                tjs++;
            }
        }
        else
        {
            if(a[tjs]>a[wjs])
            {
                ans+=a[wjs];
                a[tjs]-=a[wjs];
                wjs--;
            }
            else if(a[tjs]<a[wjs])
            {
                ans+=a[tjs];
                a[wjs]-=a[tjs];
                tjs++;
            }
            else
            {
                ans+=a[wjs];
                wjs--;
                tjs++;
            }
        }
    }
    cout<<ans;
    return 0;
}
