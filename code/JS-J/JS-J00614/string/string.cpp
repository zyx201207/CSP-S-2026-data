#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    char c;
    ll st,ed;
}s[200010];
ll n,ans=0,l=0,lst;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll a;
        char c_;
        cin>>a>>c_;
        l+=a;
        s[i].c=c_;
        s[i].st=s[i-1].ed+1;
        s[i].ed=s[i].st+a-1;
    }ll pos=1;
    lst=n;
    for(ll i=1;i<=l/2;i++){
        if(i>s[pos].ed)pos++;
        char c0=s[pos].c;
        ll id=l+1-i;
        ll pos2=lst;
        while(1){
            if(s[pos2].st<=id&&s[pos2].ed>=id)break;
            pos2--;
        }lst=pos2;
        char c1=s[pos2].c;
        if(c0!=c1)ans++;
    }cout<<ans;
    return 0;
}
