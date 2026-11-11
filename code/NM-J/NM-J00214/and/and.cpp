#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int max1,sum,ans,hqr;
bool flag;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        max1=max(max1,a[i]);
        if(i==1) sum=a[i];
        else sum&=a[i];
    }
    if(m==1) cout<<max1;
    else if(m==n) cout<<sum;
    else if(m==2){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i!=j) ans=max(ans,a[i]&a[j]);
            }
        }
    cout<<ans;
    }
    else if(m==n-1){
        for(int i=1;i<=n;++i){
            int u;
            for(int j=1;j<=n;++j){
                if(j!=i&&!flag){
                    u=a[j];
                    flag=1;
                }
                if(j!=i&&flag) u&=a[j];
            }
            hqr=max(hqr,u);
        }
        cout<<hqr;
    }
    else{
        sort(a+1,a+1+n);
        int q=a[n];
        for(int i=n-1;i>=n-m+1;--i) q&=a[i];
        cout<<q;
    }
    return 0;
}
