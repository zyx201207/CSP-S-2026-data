#include<bits/stdc++.h>
using namespace std;
long long n,o,m,ans=1;
long long a[500005];
struct res{
    bool ch=1;
    long long s=1;
};
res check(long long x){
    res r;
    for(int i=x-1;i>=1;i--){
        if(o<a[i]){
            //cout<<o<<" "<<i<<" "<<a[i]<<endl;
            //cout<<endl;
            r.ch=0;
            return r;
        }
        o-=a[x]-a[i];
        r.s++;
        //cout<<o<<" "<<i<<" "<<a[i]<<endl;
    }
    return r;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,r=n,mi;
    while(l<=r){
        mi=(l+r)/2;
        o=m;
        res rs=check(mi);
        ans=max(rs.s,ans);
        if(rs.ch){
            l=mi+1;
        }else{
            r=mi-1;
        }
        //cout<<mi<<" "<<ans<<endl;
        //cout<<"---"<<endl;
    }
    cout<<ans;
    return 0;
}
