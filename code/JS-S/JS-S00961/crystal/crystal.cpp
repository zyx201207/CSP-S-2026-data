#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    int m;
    int c=0;
    int d=1;
    int ans=0;
    cin>>n;
    cin>>m;
    long long a[n+1];
    long long b[n+5][n+5];
    for(int i=1;i<=n+5;i++){
        for(int j=1;j<=n+5;j++){
            b[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sort(a[1],a[i]);
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]>=a[i]){
                b[i][j]=a[j]-a[i];
            }
        }
    }

    for(int i=2;i<=n;i++){
        d=1;
        c=0;
        for(int j=1;j<=n;j++){
            if(b[j][i]!=-1){
                c=c+b[j][i];
                if(c<=m){
                    d++;
                }
                ans=max(ans,d);
            }
        }
    }
    cout<<ans;
}
