#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+2;
int n;
ll ans=0;
ll sum[maxn];
struct node{
    ll a;
    char c;
}s[maxn];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        sum[i]=sum[i-1]+s[i].a;
    }
    int idf=1,idd=n;
    ll fr=1,hd=sum[n];
    while(fr<hd){
        int mn=min(sum[idf]-fr+1,hd-sum[idd-1]);
        if(s[idf].c!=s[idd].c) ans+=mn;
        if(mn==sum[idf]-fr+1) idf++;
        if(mn==hd-sum[idd-1]) idd--;
        fr+=mn;
        hd-=mn;
    }
    cout<<ans;
    return 0;
}
