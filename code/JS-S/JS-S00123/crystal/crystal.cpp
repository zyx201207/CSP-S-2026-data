#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<long long> a;
vector<long long> sum;
bool check(int x){
    long long tmp=2e18;
    for(int i=x;i<=n;i++){
        tmp=min(tmp,(x-1)*a[i]-sum[x-1]+sum[i-x]);
        if(tmp<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    a.resize(n+1);
    sum.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1;
    int r=n;
    int mid=0;
    while(l<r){
        mid=(l+r+1)/2;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    mid=(l+r)/2;
    cout<<mid;
    return 0;
}
