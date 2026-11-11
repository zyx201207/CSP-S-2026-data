#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,y,a[N],ma=0,cma=0;
int c[N],ans=0,b[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(c,0,sizeof(c));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;
        if(c[a[i]]>=2) cma=max(cma,a[i]);
        ma=max(ma,a[i]);
    }
    if(m==1){
        cout<<ma;
        return 0;
    }
    if(m==2){
        int mma;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            for(int j=i;j<=m;j++){
                b[j]=a[j]&a[j+1];
                mma=max(mma,b[j]);
            }
        }
        cout<<mma;
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=1;i<n;i++){
            ans=ans&a[i+1];
        }
        cout<<ans;
        return 0;
    }
    cout<<cma;
    return 0;
}
