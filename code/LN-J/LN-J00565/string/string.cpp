#include<bits/stdc++.h>
using namespace std;
long long n,len,olen,ans;
string o,a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>len>>a;
        olen+=len;
        for(long long j=1;j<=len;j++){
            o+=a;
        }
    }
    for(long long i=0;i<=olen/2-1;i++){
        if(o[i]!=o[olen-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
