#include<bits/stdc++.h>
using namespace std;
using in=long long;
in b[5005][5005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    in n,m,a[500005]={};
    cin>>n>>m;
    in sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=llabs(a[i]);
    }
    if(m>=sum){
        cout<<n;
        return 0;
    }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                b[i][j]=llabs(a[i]-a[j]);
            }
        }
        for(int i=1;i<=n;i++){
            sort(b[i]+1,b[i]+n+1);
        }
        in ans=0;
        for(int i=1;i<=n;i++){
            in z=0,cnt=0;
            for(int j=1;j<=n;j++){
                if(z+b[i][j]<=m){
                    cnt++;
                    z+=b[i][j];
                }
                else{
                    break;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
        return 0;

    in r=0;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]==a[2]-a[1]){
            r++;
        }
    }
    if(r==n-1){
        in cnt=1;
        in z=a[2]-a[1],w=(n+1)/2+1,q=(n+1)/2-1;
        in e=z;
        while(m>=z){
            if(w>0){
                m-=z;
                cnt++;
            }
            if(m<z)break;
            if(q<=n){
                m-=z;
                cnt++;
            }
            z+=e;
        }
        cout<<cnt;
        return 0;
    }
    cout<<1;
    return 0;
}
