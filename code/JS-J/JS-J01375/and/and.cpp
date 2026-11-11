#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
void task1(){
    int res=0;
    for(int i=0;i<(1<<n);i++){
        int cnt=0,ans=0;
        bool f=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                cnt++;
                if(f==0)f=1,ans=a[j+1];
                else ans&=a[j+1];
            }
        }
        if(cnt==m)res=max(res,ans);
    }
    cout<<res<<"\n";
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==m){
        int ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
    }
    else if(m==1){
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        cout<<ans;
    }
    else if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
        }
        cout<<ans;
    }
    else if(n<=20)task1();
    else{
        sort(a+1,a+n+1);
        int ans=a[n];
        for(int i=n-1;i>=n-m+1;i--)ans&=a[i];
        cout<<ans;
    }
    return 0;
}

