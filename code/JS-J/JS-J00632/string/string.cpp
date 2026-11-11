#include <bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
    long long q;char u;
};
node b[200008];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i].q>>b[i].u;
    }
    long long l=1,r=n;
    while(l<r)
    {
        if(b[l].u!=b[r].u)
        {
            if(b[l].q>b[r].q)
            {
                b[l].q-=b[r].q;
                ans+=b[r].q;
                r--;
            }
            else if(b[l].q<b[r].q)
            {
                b[r].q-=b[l].q;
                ans+=b[l].q;
                l++;
            }
            else
            {
                ans+=b[l].q;
                l++;r--;
            }
        }
        else
        {
            if(b[l].q>b[r].q)
            {
                b[l].q-=b[r].q;
                r--;
            }
            else if(b[l].q<b[r].q)
            {
                b[r].q-=b[l].q;
                l++;
            }
            else
            {
                l++;r--;
            }
        }
        cout<<ans<<" ";
    }
    cout<<ans;
    return 0;
}
