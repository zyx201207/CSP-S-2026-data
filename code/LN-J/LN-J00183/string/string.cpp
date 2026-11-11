#include<bits/stdc++.h>
using namespace std;
struct science
{
    long long a;
    char c;
};
science v[300000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m=0,l=0,r=1,k=0,h;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>v[i].a>>v[i].c;
    }
    h=n;
    while(h>0)
    {
        if(v[l].c!=v[n-r].c)
        {
            k+=min(v[l].a,v[n-r].a);
        }
        if(v[l].a>v[n-r].a)
        {
            v[l].a-=v[n-r].a;
            r++;
        }
        else if(v[l].a<v[n-r].a)
        {
            v[n-r].a-=v[l].a;
            l++;
        }
        else
        {
            l++;
            r++;
        }
        h=n-l-r+1;
    }
    cout<<k;
    return 0;
}
