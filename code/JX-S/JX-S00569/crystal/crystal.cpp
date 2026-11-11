#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=5e5+10;
int n,m;
int a[N],b[N],c;
bool check(int cnt){
    int res=0;
    for(int i=1;i+cnt<=m;i++){
        res=0;
        for(int j=i;j<=cnt;j++){
            res+=b[j]-b[cnt];
            //cout<<"debug: "<<res;
            if(res>m)return false;
        }
        return true;
    }
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[n]-a[i];//8 7 5 1 0
    }
    int l=0,r=n,ans;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
            //cout<<"debug: "<<ans;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
