#include<bits/stdc++.h>
using namespace std;
int a[100100],ans,n,m,maxn,b[21];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    else if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    else if(m==n){
        int x=a[1];
        for(int i=2;i<=n;i++)x=x&a[i];
        cout<<x;
    }
    else{
        int x=0;
        for(int i=1;i<(2<<n);i++){
            int k=i,cnt=0;
            for(int j=1;j<=n;j++){
                b[j]=k%2;
                if(k%2==1)cnt++;
                k=k/2;
            }
            if(cnt==m){
            int ans=(2<<20)-1;
            for(int j=1;j<=n;j++){
                if(b[j]){
                    ans=ans&a[j];
                }
            }
    x=max(x,ans);
            }
        }
    cout<<x;
    }
    return 0;
}
