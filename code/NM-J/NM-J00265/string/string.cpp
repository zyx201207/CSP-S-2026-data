#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define int long long
int n;
int a[200001];
char b[200001];
int z=1,y;
int c;
char d;
bool e;
int ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    y=n;
    for(int i=1;i<=n;i++)
    {
        if(z>y)
            break;
        if(c)
        {
            if(e)
            {
                if(d!=b[y])
                    ans+=min(c,a[y]);
                if(c>a[y])
                {

                    c-=a[y];
                    y--;
                    continue;
                }
                c=0;
                a[y]-=c;
            }
            else
            {
                if(d!=b[z])
                    ans+=min(c,a[z]);
                if(c>a[z])
                {
                    c-=a[z];
                    z++;
                    continue;
                }
                c=0;
                a[z]-=c;
            }
        }
        if(b[z]!=b[y])
            ans+=min(a[z],a[y]);
        if(a[z]>a[y])
        {
            c=a[z]-a[y];
            d=b[z];
            e=1;
        }
        if(a[y]>a[z])
        {
            c=a[y]-a[z];
            d=b[y];
            e=1;
        }
        z++;
        y--;
    }
    cout<<ans;
    return 0;
}
