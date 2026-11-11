#include <bits/stdc++.h>
using namespace std;

int q;
struct node{
    long long a;
    char c;
}n[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>n[i].a>>n[i].c;
    }
    int l=1,r=q;
    long long ans=0;
    while(l<=r)
    {
        int s=abs(n[l].a-n[r].a);
        if(n[l].a>n[r].a)
        {
            n[l].a=s;
            if(n[l].c!=n[r].c) ans+=n[r].a;
            r--;
        }
        else
        {
            n[r].a=s;
            if(n[l].c!=n[r].c) ans+=n[l].a;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
