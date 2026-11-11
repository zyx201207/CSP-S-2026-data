#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans;
struct S
{
    ll cnt;
    char ch;
}s[200100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>s[i].cnt>>s[i].ch;
    }
    
    ll l=0,r=n-1;
    ll lrem=s[l].cnt;
    ll rrem=s[r].cnt;
    ll ans=0;
    while(l<r)    {
        ll take=min(lrem,rrem);
        if(s[l].ch!=s[r].ch){
            ans+=take;
        }
        lrem-=take;
        rrem-=take;
        if(lrem==0){
            l++;
            if(l<=r)
            {
                lrem=s[l].cnt;
            }
        }
        if(rrem==0){
            r--;
            if(l<=r)
            {
                rrem=s[r].cnt;
            }
        }

    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}