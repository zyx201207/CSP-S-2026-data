#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long f=1,t=a[2]-a[1];
    for(int i=2;i<=n&&f;i++)
        if(a[i]-a[i-1]!=t)
            f=0;
    if(f){
        long long ans=1;
        for(;(ans+1)*ans<=(long double)(2*m)/t;ans++);
        cout<<ans<<"\n";
        return 0;
    }
    for(int len=n;len;len--){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            long long cnt=0;
            for(int i=l;i<r;i++){
                cnt+=a[r]-a[i];
                if(cnt>m){
                    cnt=-5388;
                    break;
                }
            }
            if(cnt!=-5388){
                cout<<len;
                return 0;
            }
        }
    }
    return 0;
}
