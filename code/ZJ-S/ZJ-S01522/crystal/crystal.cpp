#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],b[N];
void qrw(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}
bool check(int len){
    for(int i=len;i<=n;i++){
        if(b[i]-b[i-len]+m>=a[i]*len){
            return 1;
        }
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    qrw();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    int l=1,r=n;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}