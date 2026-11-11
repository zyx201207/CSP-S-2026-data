#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a[200005];
    long long b[200005],n,l=1,r,m=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i]>>a[i];
    }
    r=n;
    while(l!=r)
    {

        if(b[l]>b[r])
        {
            if(a[l]==a[r])
            {

                b[l]-=b[r];
                r--;
            }
            else
            {
                m+=b[r];
                b[l]-=b[r];
                r--;
            }
        }
        else
        {
            if(a[l]==a[r])
            {

                b[r]-=b[l];
                l++;
            }
            else
            {
                m+=b[l];
                b[r]-=b[l];
                l++;
            }
        }
    }
    cout<<m;
}

