#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,res=1;
ll m,a[N],d;
bool check(int mid,ll bal,int step){
    ll sum=0;
    for(int i=step-mid+1;i<=step;++i){
        sum+=bal-a[i];
        // cerr<<i<<" "<<sum<<"\n";
    }
    return sum<=m;
}
void solveA(){
    ll mx=sqrt(2*m);
    for(ll i=mx;i>=0;--i){
        if((1+i)*i/2<=m){
            cout<<i+1;
            break;
        }
    }
    return;
}
void solveB(){
    ll mx=sqrt(2*m*1.0/d);
    for(ll i=mx;i>=0;--i){
        if((1+i)*i/2*d<=m){
            cout<<i+1;
            break;
        }
    }
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n>5000){
        bool fA=1,fB=1;
        d=a[2]-a[1];
        for(int i=2;i<=n;++i){
            if(a[i]-a[i-1]!=d)fB=0;
            if(a[i]!=i)fA=0;
        }
        if(fA){
            solveA();
            return 0;
        }else if(fB){
            solveB();
            return 0;
        }
    }
    for(int i=1;i<=min(n,5000);++i){
        int l=1,r=i,ans=-1;
        while(l<=r){
            int mid=l+r>>1;
            // cerr<<mid<<" "<<check(mid,a[i],i)<<endl;
            if(check(mid,a[i],i)){
                l=mid+1;
                ans=mid;
            }else{
                r=mid-1;
            }
        }
        // cerr<<ans<<" ";
        res=max(res,ans);
    }
    cout<<res;
    return 0;
}
/*
5 5
1 2 4 8 9
*/