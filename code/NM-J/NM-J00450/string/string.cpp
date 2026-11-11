#include<bits/stdc++.h>
#define il long long
using namespace std;
struct n
{
    int x,id;
    char c;
}f[6666];
int n;
long long m;
il s;
bool fe=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>f[i].x>>f[i].c;
        s=f[i].x;
        if(i>=1)
        {
            if(f[i].c!=f[i-1].c)
            {
                fe=0;
            }
        }
    }
    if(fe==0)
    {
        cout<<s/2;
    }
    else cout<<0;
    return 0;
}
