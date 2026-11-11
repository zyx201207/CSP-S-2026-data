#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=1e18+10,MAX=1e12+10;
int n,m,ans;
int a[N];
int cha=-1;
bool is_sp=1;
int find(int t,int l){
    int r=n,ret;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]<=t){
            ret=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ret;
}
int check(int mid){
    int cnt=0,tar=a[mid],ret=0;
    // for(int i=find(tar,mid);i>=1;i--){
    for(int i=mid;i>=1;i--){
        if(a[i]<tar){
            cnt+=tar-a[i];
            ret++;
        }
        else if(a[i]==tar){
            ret++;
        }
        if(cnt>m)break;
    }
    if(cnt>m){
        return -1;
    }else{
        return ret;
    }
}
void sp(){
    cha=abs(cha);
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        int t=mid*cha*(mid-1)/2;
        if(t<=m){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(cha==-1&&i==2){
            cha=a[2]-a[1];
        }
        if(is_sp&&i>2){
            if(a[i]-a[i-1]!=cha){
                is_sp=0;
            }
        }
    }
    if(is_sp){
        sp();
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        if(a[i]==a[i+1])continue;
        ans=max(ans,check(i));
    }
    // while(l<=r){
    //     mid=(l+r)>>1;
    //     int t=check(mid);
    //     if(t>=0){
    //         ans=t;
    //         l=mid+1;
    //     }else{
    //         r=mid-1;
    //     }
    // }
    cout<<ans;

    return 0;
}