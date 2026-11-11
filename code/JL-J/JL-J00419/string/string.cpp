#include<bits/stdc++.h>
using namespace std;
long long l = 1,r = 0,n,a[1000005],ans,lw,rw;
char b[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>b[i];
        r += a[i];
        a[i] += a[i - 1];
    }
    lw = 1;
    rw = n;
    for(int i = l;i <= r;i++){
            if(l >= r){
                break;
            }
        if(b[lw] == b[rw]){
            l += min(a[lw],a[rw]);
            r -= min(a[lw],a[rw]);
        }
        else{
            ans += min(a[lw],a[rw]);
            l += min(a[lw],a[rw]);
            r -= min(a[lw],a[rw]);
        }
        if(l >= a[lw]) lw++;
        if(r <= a[rw]) rw--;
    }
    cout<<ans;
    return 0;
}
