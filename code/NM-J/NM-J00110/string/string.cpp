#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,l;
string s;
struct p{
    ll a;
    char c;
}a[N];

void x(){
    for(int i=1;i<=n;i++){
        l+=a[i].a;
        for(int j=0;j<a[i].a;j++){
            s+=a[i].c;
        }
    }
    s=" "+s;
    int ans=0;
    for(int i=1;i<=l/2;i++){
        if(s[i]!=s[l-i+1]){
            ans++;
        }
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
    }
    x();

    return 0;
}
