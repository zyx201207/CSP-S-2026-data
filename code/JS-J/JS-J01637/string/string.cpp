#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,cnt=0;
struct node{
    ll k;
    char c;
}a[200005];
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        cin>>a[i].k>>a[i].c;
        ll h=a[i].k;
        while(h--){
        s+=a[i].c;
        }
    }
    cout<<s<<" ";
    ll p=s.size();
    for(ll i=0;i<s.size()/2;i++){
        if(s[i]==s[--p])continue;
        s[p]=s[i];
        cnt++;
}
    printf("%lld",cnt);
    return 0;
}
