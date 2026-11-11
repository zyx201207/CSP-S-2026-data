#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=2e5+5;
struct str{
    ll a,vbegin,vend;
    char c;
}s[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ans=0,l=1;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        s[i].vbegin=l;
        cin>>s[i].a>>s[i].c;
        l+=s[i].a;
        s[i].vend=l-1;
    }
    l--;
    int sl=1,sr=n,mid=l/2;
    for(int i=1;i<=mid;i++){
        if(s[sl].vend<i)sl++;
        if(s[sr].vbegin>l-i+1)sr--;
        if(s[sl].c!=s[sr].c)ans++;
    }
    cout<<ans;
    return 0;
}
