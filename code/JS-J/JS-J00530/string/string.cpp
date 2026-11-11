#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
string c[200005];
int n;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int ans=0;
    string s2=s;
    reverse(s.begin(),s.end());
    for(int i=1;i<=(s.size()+1)/2;i++){
        if(s[i-1]!=s2[i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
