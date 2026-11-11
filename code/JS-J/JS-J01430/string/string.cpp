#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node{
    ll x;
    char c;
}a[200005];
int main()
{
    freopen("string6.in","r",stdin);
    //freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
    string s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i].x;j++){
            s=s+a[i].c;
        }
    }
    int ans=0;
    int nm=s.size();
    nm-=1;
    if(nm%2==0){
        int m=nm/2;
        for(int i=1;i<=m;i++){
            if(s[i]!=s[n-i+1]) ans++;
        }
        cout<<ans;
    }else{
        int m=(nm+1)/2;
        for(int i=1;i<=m-1;i++){
            if(s[i]!=s[n-i+1]) ans++;
        }
        cout<<ans;
    }
    return 0;
}
