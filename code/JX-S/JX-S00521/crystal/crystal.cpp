#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+100;
int n,m,maxs=1;
int a[N],qzh[N];

bool check(int i,int x){
    int sum=0;
    sum=((x-i)*a[x]-(qzh[x-1]-qzh[i-1]));
    return sum<=m;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        qzh[i]=qzh[i-1]+a[i];
    }
    for(int i=1;i<n;i++){
        int l=i+1,r=n,ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(i,mid)){
                l=mid+1;
                ans=mid;
            }else r=mid-1;
        }
        maxs=max(maxs,ans-i+1);
    }
    cout<<maxs;
    return 0;
}
