#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        int maxa=0;
        for(int i=1;i<=n;i++){
            if(a[i]>maxa)maxa=a[i];
        }
        cout<<maxa;
        return 0;
    }
    else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    else if(m==2){
        int maxa=a[1]&a[2];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]&a[j]>=maxa&&i!=j)maxa=a[i]&a[j];
            }
        }
        cout<<maxa;
        return 0;
    }
    else if(m==n-1){
        sort(a+1,a+n+1);
        int ans=a[2];
        for(int i=3;i<=n;i++)ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1,greater<int>());
    long long ans=a[1];
    for(int i=2;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
