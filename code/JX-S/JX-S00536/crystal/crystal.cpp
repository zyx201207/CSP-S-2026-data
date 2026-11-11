#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ress;
bool cmp(int x,int y){
    return x<y;
}
long long check(int l){
    int ans=-1;
    for(int i=l;i<=n;i++){
        long long sum=s[i]-s[l-1],need=a[i]*(i-l+1);
        int cost=need-sum;
        if(cost<=m){
            ans=i;
        }
    }
    int re;
    if(ans==-1)re=-1;
    else re=ans-l+1;
    return re;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<=r){
        if(r-l==1){
            long long res1=check(l);
            long long res2=check(r);
            ress=max(ress,res1);
            ress=max(ress,res2);
        }
        int mid=(l+r)/2;
        long long res=check(mid);
        if(res==-1){
            l=mid+1;
        }
        else{
            r=mid-1;
            ress=max(ress,res);
        }
    }
    cout<<ress;
    return 0;
}
