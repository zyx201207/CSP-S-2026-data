#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],d[N];
bool SP=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
            SP=0;
        }
    }
    sort(a+1,a+n+1);
    if(SP){
        int ans=1,d=a[2]-a[1];
        for(int k=1;k<=n;k++){
            int l=-1,r=k+1;
            while(l<r-1){
                int mid=(l+r)/2;
                if((1+(a[k]-a[mid]))*(k-mid+1)/2<=m){//等差数列求和
                    //能，尝试更小
                    r=mid;
                }
                else{
                    l=mid;
                }
            }
            ans=max(ans,k-r+1);
        }
        cout<<ans;
        return 0;
    }
    int ans=1;
    for(int k=1;k<=n;k++){
        int cnt=1,t=m;
        for(int i=k-1;i>=1;i--){
            int x=a[k]-a[i];
            if(t-x>=0){
                t-=x;
                cnt++;
            }
            else{
                break;
            }
        }
        //maybe预处理+二分
        /*
        //但预处理啥能做到O(1)或O(log n)计算sum(s[k]-s[i])呢,O(n log^2 n)约等于8e7也能过
        //前面的优化有时间再来写吧！
        */
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}