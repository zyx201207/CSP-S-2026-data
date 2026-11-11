#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int a;
    char c;
};
long long ans;
node S[200011];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int g=1;g<=n;g++)
    {
        cin>>S[g].a>>S[g].c;
    }
    int l=1,r=n;
    ans=0;
    while(l<r)
    {
        if(S[l].c!=S[r].c)ans+=min(S[l].a,S[r].a);
        if(S[l].a>S[r].a)
        {
            S[l].a-=S[r].a;
            r--;
        }
        else if(S[l].a==S[r].a)
        {
            r--;
            l++;
        }
        else
        {
            S[r].a-=S[l].a;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
