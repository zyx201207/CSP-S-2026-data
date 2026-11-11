#include<bits/stdc++.h>
using namespace std;
int a[500005];
int h[300005];//last_pos
int ans[300005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(h,0,sizeof(h));
        for(int j=i;j<=n;j++){
            if(h[a[i]]!=0){
                for(int k=h[a[j]];k<j;k++){
                    h[a[k]]=0;
                }
            }
            h[a[i]]=j;
        }
        for(int j=1;j<=m;j++){
            if(h[j]!=0)ans[j]++;
        }
    }
    for(int j=1;j<=m;j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}
/*
小猫钓鱼？
nonono小鱼钓cCf
*/