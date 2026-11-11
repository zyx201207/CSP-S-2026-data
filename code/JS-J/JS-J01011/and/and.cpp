#include<bits/stdc++.h>
using namespace std;
int n,m,a[100011],dp[100011],vis[100011],maxx,maxy,maxz;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);

    }
    int s=a[1];
    for(int i=2;i<=n;i++){
        s=s&a[i];
    }
    if(m==n){
        cout<<s;
        return 0;
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }


    if(m==2){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(maxy<a[i]&a[j]){
                maxy=a[i]&a[j];

            }
        }
    }
        cout<<maxy;
        maxy=0;
        return 0;
    }

    if(m==3){
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(maxy<a[i]&a[j]&a[k]){
                    maxy=a[i]&a[j]&a[k];
                }
            }

        }
    }
    cout<<maxy;
    return 0;
    }
    cout<<0;
    return 0;
}
