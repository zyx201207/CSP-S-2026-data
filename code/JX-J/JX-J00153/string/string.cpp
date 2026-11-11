#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,char>
#define fi first
#define se second
const int N=200050;
int n;string s;
ll ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;char y;
        scanf("%d",&x);cin>>y;
        for(int i=1;i<=x;i++) s+=y;
    }
    ll l=s.size();
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]) ans++;
    }
    printf("%lld",ans);
    return 0;
}
