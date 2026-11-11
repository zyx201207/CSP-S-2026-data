#include<bits/stdc++.h>
using namespace std;
int a[200005]={};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ma=-1;
    int cnt=1;
    if(m==1){
        for(int i=1;i<=n;i++){
            ma=max(ma,a[i]);
        }
        cout<<ma;
    }
    else if(m==n){
        for(int i=1;i<=n;i++){
            cnt=(cnt && a[i]);
        }
        cout<<ma;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cnt=(a[i] && a[j]);
                ma=max(cnt,ma);
                cnt=0;
            }
        }
        cout<<ma;
    }
    else if(m=n-1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                cnt=(cnt && a[j]);
            }
            ma=max(ma,cnt);
            cnt=0;
        }
        cout<<ma;
    }
    return 0;
}
