#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a;
    char c;
};
node s[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
    }
    long long step=0;
    int l=1,r=n;
    while(l<r)
    {
        if(s[l].c!=s[r].c)
        {
            step+=min(s[l].a,s[r].a);
        }
        if(s[l].a>s[r].a)
        {
            s[l].a-=s[r].a;
            r--;
        }
        else if(s[l].a<s[r].a){
            s[r].a-=s[l].a;
            l++;
        }
        else
        {
            l++;
            r--;
        }
    }
    cout<<step;
    return 0;
}
