#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n;
ll m;
ll a[N];
ll cha[N];
bool check(int x){
    for(int i=x;i<=n;i++){
        if(cha[i]-cha[i-x]-(i-x)*(a[i]-a[i-x])<=m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        cha[i]=cha[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    int l=1,r=n,mid,ret=-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ret=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<ret<<'\n';
    return 0;
}
