#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
int ans=1;
long long m;
long long a[N];
long long S[N];
long long get_cost(int l,int r){
    long long res=(r-l+1)*a[r];
    res-=S[r]-S[l-1];
    return res;
}
int query(int x){
    int l=1,r=x;
    while(l<r){
        int mid=(l+r)>>1;
        if(get_cost(mid,x)<=m){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return x-l+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        S[i]=S[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,query(i));
    }
    cout<<ans<<'\n';
    return 0;
}