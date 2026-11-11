#include<bits/stdc++.h>
using namespace std;
long long a[200005],n;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long sum = 0;
    for(long long i = 1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    long long l = 1,r = n,ans = 0;
    while(l<=r){
        long long ts = 0;
        while(l<r){
            if(ts == a[l]) break;
            if(ts+a[r]<=a[l]){
                if(c[r]!=c[l]) ans+=a[r];
                ts+=a[r];
                r--;
            }
            else{
                if(c[r]!=c[l]) ans+=(a[l]-ts);
                a[r] = ts+a[r]-a[l];
                break;
            }
        }
        l++;
    }
    cout<<ans;
    return 0;
}
