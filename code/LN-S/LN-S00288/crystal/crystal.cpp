#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int a[500010];
int pre[500010];
int s(int i,int j){//区间i到j的代价，答案为j-i+1
    return pre[j]-pre[i]-(i-1)*(a[j]-a[i]);
}
bool check(int x,int r){
    if(s(x,r)<=m)
        return true;
    else return false;
}
int cha(int rr){//查找当前r下最左的左端点
    int l=1;
    int r=rr;
    int ans=r;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid,rr)){
            r=mid;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    pre[1]=0;
    for(int i=1;i<n;i++){
        pre[i+1]=pre[i]+i*(a[i+1]-a[i]);
    }
    int maxx=1;
    for(int r=1;r<=n;r++){
        int l=cha(r);
        int len=r-l+1;
        maxx=max(maxx,len);
    }
    cout<<maxx;




}
