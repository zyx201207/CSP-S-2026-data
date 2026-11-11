#include<bits/stdc++.h>
using namespace std;
int f[200005][2005]={};
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
        int maxn=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            maxn=max(maxn,x);
        }
        cout<<maxn;
    }
    else if(m==n){
        int x;
        cin>>x;
        for(int i=1;i<n;i++){
            int y;
            cin>>y;
            x&=y;
        }
        cout<<x;
    }
    else if(m==2){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int maxn=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
    }else{
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=1;i<=n;i++){
            f[i][1]=a[i];
            for(int j=2;j<=m;j++){
                f[i][j]=max(f[i-1][j-1]&a[i],f[i-1][j]);
            }
        }
        cout<<f[n][m];
    }
}
