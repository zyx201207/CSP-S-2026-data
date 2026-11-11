#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],s[500005];
bool f;
bool check(int x){
    for(int i=x;i<=n;i++){
        int tzhi=s[i]-s[i-x],mzhi=a[i]*x;
        if(mzhi-tzhi<=m){
            return 1;
        }
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1])f=1;
    }
    if(!f){
        cout<<n;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){s[i]=s[i-1]+a[i];}
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        //cout<<mid<<' '<<l<<' '<<r<<endl;//debug
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
