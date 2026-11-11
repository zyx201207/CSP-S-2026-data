#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
            int mx=0;
        for(int i=1;i<=n;i++)mx=max(mx,a[i]);
    cout<<mx;
    }else if(m==2){
        int mx=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                mx=max(mx,(a[i]&a[j]));
            }
        }
        cout<<mx;
    }else if(m==n){
        int mx=a[1];
        for(int i=2;i<=n;i++){
            mx=(mx&a[i]);
        }
        cout<<mx;
    }else if(m==n-1){
        int mx=a[1];
        for(int i=2;i<=n;i++){
            mx=(mx&a[i]);
        }
        int mx1=0;
        for(int i=1;i<=n;i++){
            mx1=max(mx1,mx|(mx^a[i]));
        }
        cout<<mx1;
    }
    return 0;
}
