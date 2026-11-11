#include <bits/stdc++.h>
using namespace std;
long long n,m,x=1048576,a[200005];
bool cmp(long long y,long long z){
    return y>z;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        x=a[1];
        for(int i=1;i<=n;i++){
            x&=a[i];
        }
        cout<<x;
    }
    else if(m==1){
        x=-1;
        for(int i=1;i<=n;i++){
            x=max(x,a[i]);
        }
        cout<<x;
    }
    else if(m==2){
        long long kmj=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                x=a[i]&a[j];
                kmj=max(kmj,x);
            }
        }
        cout<<kmj;
    }
    else{
        sort(a+1,a+n+1,cmp);
        x=a[1];
        for(int i=1;i<=m;i++){
            x&=a[i];
        }
        cout<<x;
    }
    return 0;
}
