#include<bits/stdc++.h>
using namespace std;
char sb[200010];
long long a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    long long sz=0;
    long long big=-1;
    bool yes=true;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>sb[i];
        sz+=a[i];
        if(sb[i]==sb[i-1]||i==1)
        {
            a[i]+=a[i-1];
        }
        else yes=false;
        if(a[i]>big)
        {
            big=a[i];
        }
    }
    if(yes)
    {
        cout<<0;
        return 0;
    }
    if(sz%2==0)
    {
        cout<<sz-big;
    }
    else
    {
        cout<<sz-big-1;
    }
    return 0;
}

