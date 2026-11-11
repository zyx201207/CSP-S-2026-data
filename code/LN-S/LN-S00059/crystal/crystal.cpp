#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int a[maxn];
int sum[maxn];
bool cmp(int x,int y){
    return x>y;
}
int ans1,ans2;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool f1=false;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=n;i>=1;i--){
        int aver=(sum[i]+m)/i;
        if(aver<a[i]) continue;
        else{
            for(int j=1;j<=min(i,m);j++){
                if((sum[i]+j)%i==0){
                    ans1=i;
                    f1=true;
                    break;
                }
            }
        }
        if(f1) break;
    }
    bool f2=false;
    sort(a+1,a+1+n,cmp);
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=n;i>=1;i--){
        int aver =(sum[i]+m)/i;
        if(aver<a[1]) continue;
        else{
            for(int j=1;j<=min(i,m);j++){
                if((sum[i]+j)%i==0){
                    ans2=i;
                    f2=true;
                    break;
                }
            }
        }
        if(f2) break;
    }
    cout<<max(ans1,ans2);
    return 0;
}
