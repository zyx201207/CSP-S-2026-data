#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans=0,b=1;
void dfs(ll x,ll y,ll z){
    if(x==n+1){
        if(z==m){
            //cout<<y;
            ans=max(ans,y);
        }
        return;
    }
    dfs(x+1,y&a[x],z+1);
    dfs(x+1,y,z);

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=21;i++){
        b*=2;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //cout<<b;
    if(n<=20){
        dfs(1,b-1,0);
    }else if(n<=2000){
        if(m==1){
            for(int i=1;i<=n;i++){
                ans=max(ans,a[i]);
            }
        }
        if(m==2){
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }
        if(m==n){
            ans=a[1];
            for(int i=2;i<=n;i++){
                ans&=a[i];
            }
        }


    }else{
        ans=a[1];
            for(int i=2;i<=n;i++){
                ans&=a[i];
            }
            for(int i=1;i<=n;i++){
                ans=max(ans,ans|a[i]);
            }

    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;

}

