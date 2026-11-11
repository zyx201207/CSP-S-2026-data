#include<bits/stdc++.h>
using namespace std;
long long n,x,l,r=-1,ans;
string s;char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&x);cin>>c;
        r+=x;
        for(long long j=1;j<=x;j++){
            s+=c;
        }
    }
    while(l<r){
        if(s[l]!=s[r]) ans++;
        l++;r--;
    }
    cout<<ans;
    return 0;
}
