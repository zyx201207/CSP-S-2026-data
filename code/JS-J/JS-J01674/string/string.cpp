#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s=s+c;
        }
    }
    int l=0,r=s.size()/2;
    if(s.size()%2==1)r++;
    for(int i=r;i<s.size();i++){
        if(s[l+i]!=s[r+i]){
            ans++;
        }
    }
    cout<<ans;
}
