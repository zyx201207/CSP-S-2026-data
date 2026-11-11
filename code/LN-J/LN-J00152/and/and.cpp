#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
const int N=2e5+8;
int a[N]={};
int mx=0,mw=pow(2,30)-1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    };
    sort(a+1,a+n+1);
    if(m==1) cout<<a[n];
    else if(m==n){
        for(int i=1;i<=n;i++) mw&=a[i];
        cout<<mw;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j) mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j!=i) mw&=a[i];
            }
            mx=max(mx,mw);
        }
        cout<<mx;
    }else {
    for(int i=n;i>=n-m+1;i--){
            mw&=a[i];
        }
        cout<<mw;
    }
    return 0;
}
