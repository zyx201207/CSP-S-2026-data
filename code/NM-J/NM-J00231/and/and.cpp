#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
        int nmax=0,a[200005];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            nmax=max(nmax,a[i]);
        }
        cout<<nmax;
    }
    else if(m==n){
        int all,a[200005];
        cin>>a[1];
        all=a[1];
        for(int i=2;i<=n;i++){
            cin>>a[i];
            all&=a[i];
        }
        cout<<all;
    }
    else if(m==n-1){
        int a[200005];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int nnmax=0;
        for(int i=1;i<=n;i++){
            int nall;
            if(i==1)nall=a[2];
            else nall=a[1];
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                nall&=a[j];
            }
            nnmax=max(nnmax,nall);
        }
        cout<<nnmax;
    }else{
        vector<int> a,f[35];
        int ans=0;
        int c[35];
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        for(int i=30;i>=0;i--){
            c[i]=0;
            f[i].clear();
            for(int x:a){
                if((x>>i)&1){
                    c[i]++;
                    f[i].push_back(x);
                }
            }
            if(c[i]>=m){
                ans+=(1<<i);
                a=f[i];
            }
        }
        cout<<ans;
    }
    return 0;
}
