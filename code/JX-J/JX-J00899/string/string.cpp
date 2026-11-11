#include<bits/stdc++.h>
using namespace std;
int n;
long long L[200005];
int a[200005];
char c[200005];
long long num;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        L[i]+=(long long)a[i];
    }
    int l=1,r=n;
    int pl=a[l],pr=a[r];
    int k=0;
    while(l<r)
    {
        if(pl==pr&&c[l]==c[r])
        {
            l++;
            r--;
            pl=a[l];
            pr=a[r];
        }
        else if(pl==pr&&c[l]!=c[r])
        {
            num+=pl;
            l++;
            r--;
            pl=a[l];
            pr=a[r];
        }
        else if(pl<pr&&c[l]==c[r])
        {
            l++;
            pr=pr-pl;
            pl=a[l];
            k=1;
        }
        else if(pl<pr&&c[l]!=c[r])
        {
            num+=pl;
            l++;
            pr=pr-pl;
            pl=a[l];
            k=1;
        }
        else if(pl>pr&&c[l]==c[r])
        {
            r--;
            pl=pl-pr;
            pr=a[r];
            k=2;
        }
        else if(pl>pr&&c[l]!=c[r])
        {
            num+=pr;
            r--;
            pl=pl-pr;
            pr=a[r];
            k=2;
        }
    }
    cout<<num;
    return 0;
}
