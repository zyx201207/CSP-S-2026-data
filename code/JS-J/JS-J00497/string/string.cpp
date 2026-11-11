#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct node
{
    ll num;
    char c;
}s[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,cnt=0;
    cin>>n;
    for(ll i=1;i<=n;++i)
    {
        cin>>s[i].num>>s[i].c;
    }
    ll l=1,r=n;
    while(l<=r)
    {
        if(s[l].c!=s[r].c)
        {
            if(s[l].num==s[r].num){cnt+=s[l].num;l+=1;r-=1;}
            else if(s[l].num>s[r].num){cnt+=s[r].num;s[l].num-=s[r].num;r-=1;}
            else{cnt+=s[l].num;s[r].num-=s[l].num;l+=1;}
        }
        else
        {
            if(s[l].num==s[r].num){l+=1;r-=1;}
            else if(s[l].num>s[r].num){s[l].num-=s[r].num;r-=1;}
            else{s[r].num-=s[l].num;l+=1;}
        }
    }
    cout<<cnt;
    return 0;
}
