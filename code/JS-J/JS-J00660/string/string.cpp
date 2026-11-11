#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll all=0,ans=0;
struct node{
    ll v;
    ll s;
    char c;
}a[202020],b[202020];
string s="#";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].v>>a[i].c;
        all+=a[i].v;
        for(int j=1;j<=a[i].v;j++){
            s+=a[i].c;
        }
    }
    //cout<<s<<" "<<all<<'\n';
    for(int i=1;i<=all/2;i++){
        if(s[i]!=s[all-i+1]) ans++;
    }
    cout<<ans<<'\n';
}