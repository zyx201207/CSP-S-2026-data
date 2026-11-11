#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,a[200005],f=1e7;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt=cnt&a[i];
    }
    if(n==m){
        cout<<cnt;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(f>a[i]){
                f=a[i];
            }
        }
        cout<<f;
        return 0;
    }
    if(m==2){
        cnt=1;
        f=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt=a[i]&a[j];
                if(cnt>f){
                    f=cnt;
                }
            }
        }
        cout<<f;
        return 0;
    }
    if(m==n-1){
        cnt=1;
        f=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cnt=cnt+a[i]&a[j];
            }
            if(cnt>f){
                f=cnt;
            }
        }
        cout<<f;
    }
    return 0;
}
