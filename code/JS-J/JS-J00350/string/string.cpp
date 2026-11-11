#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,xxx,ans;
string s,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>xxx>>b;
        for(int j=1;j<=xxx;j++){
            s+=b;
        }
    }
    ll le=s.size();
    for(int i=0;i<le/2;i++){
        if(s[i]!=s[le-1-i]) ans++;
    }
    cout<<ans;
    return 0;
}
