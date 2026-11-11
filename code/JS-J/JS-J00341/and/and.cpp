#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,m,a[N];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==2){
        long long ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    bool f1=1,f2=1,f3=1;
    for(long long i=1;i<=n;i++){
        long long cnt=a[i];
        while(cnt!=0){
            if(cnt%2==0){
                f1=0;
                break;
            }
            cnt=cnt>>1;
        }
        if(f1==0) break;
    }

    if(f1){//A
        cout<<a[m];
        return 0;
    }
    long long cnt=n-1;
    while(cnt!=0){
        if(cnt%2==0){
            f2=0;
            break;
        }
        cnt=cnt>>1;
    }
    if(f2){
        for(long long i=1;i<=n;i++){
            if(a[i]!=i-1){
                f3=0;
                break;
            }
        }
    }
    if(f2&&f3){//B
        long long ans=a[1];
        for(long long i=2;i<=m;i++) ans=ans&a[i];
        cout<<ans;
    }else if(m==1) cout<<a[1];
    else{
        long long ans=a[1];
        for(long long i=2;i<=m;i++) ans=ans&a[i];
        cout<<ans;
    }
    return 0;
}
