#include<bits/stdc++.h>
using namespace std;
long long l,r,ans,n,lpos,rpos;
long long a[300005];
char c[300005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    lpos = 1;
    rpos = n;
    while(lpos<=rpos){
        if(lpos == rpos){
            break;
        }
        else{
            long long minv = min(a[lpos],a[rpos]);
            if(c[lpos] != c[rpos]){
                ans+=min(a[lpos],a[rpos]);
            }
            a[lpos]-=minv;
            a[rpos]-=minv;
            if(a[lpos] == 0){
                lpos++;
            }
            if(a[rpos] == 0){
                rpos--;
            }
        }
    }
    cout<<ans;
    return 0;
}
