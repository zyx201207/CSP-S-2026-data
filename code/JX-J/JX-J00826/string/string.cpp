#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
string b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
    }
    long long l=1,r=n,s=0;
    while(true)
    {
        if(b[l]==b[r])
        {
            if(a[l]>a[r])
            {
                a[l]=a[l]-a[r];
                r--;
            }
            else if(a[l]<a[r])
            {
                a[r]=a[r]-a[l];
                l++;
            }
            else
            {
                l++;
                r--;
            }
        }
        else
        {
            if(a[l]>a[r])
            {
                s=s+a[r];
                a[l]=a[l]-a[r];
                r--;
            }
            else if(a[l]<a[r])
            {
                s=s+a[l];
                a[r]=a[r]-a[l];
                l++;
            }
            else
            {
                s=s+a[l];
                l++;
                r--;
            }
        }
        if(l>=r) break;
    }
    cout<<s<<endl;
    return 0;
}
