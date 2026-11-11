#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int pp;
int f[600000];
int maxn[600000];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int w=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
     for(int i=1;i<=n;i++){
        int r=f[1];
        if(f[i]!=f[i+1]){
            if(m==0){
                cout<<0;
                return 0;
            }
        }
        if(f[i]==r){
            pp++;
        }
    }
    if(pp==n){
        cout<<n;
        return 0;
    }
    sort(f+1,f+n+1);
    for(int r=2;r<=n;r++){
        for(int l=1;l<r;l++){
            int sum=0;
            int cnt=m;
            int ans=0;
            for(int i=r-1;i>=l;i--){
                ans+=f[r]-f[i];
                if(ans<=m){
                    cnt-=f[r]-f[i];
                    sum++;
                }
                if(ans>=m){
                    w=max(sum,w);
                    continue;
                }
            }
            if(cnt>0){
                w=max(sum,w);
            }

        }
    }
    if(w==0){
        cout<<w;
    }
    else{
        cout<<w+1;
    }
    return 0;
}
