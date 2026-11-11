#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N],b[N];
int n,m;
long long vis[30],ans,maxn,maxn1,f;
int dfs(int p,int cnt){
    if(p==m){
        ans = max(ans,cnt);

    }
    else{
        for(int i = 1;i <= n;i++){

            if(!vis[i]){
                vis[i]=1;
                b[p]  = cnt;
                cnt = (cnt&a[i]);


                dfs(p+1,cnt);
                vis[i]=0;
                cnt=b[p];
            }
        }
    }

}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i]!=i-1) f=1;
        maxn = max(maxn,a[i]);
    }
    if(n<=20){

        dfs(0,1023);
        cout<<ans<<endl;
    }
    else{
        if(m==1){
            cout<<maxn<<endl;
            return 0;
        }
        if(m==2){
            for(int i = 1;i <= n;i++){
                for(int j = i;j <= n;j++){
                    maxn1 = max(maxn1,(a[i]&a[j]))
                }
            }
            cout<<ans<<endl;
            return 0;
        }
        if(m==n){
            ans = a[1];
            for(int i = 1;i <= n;i++){
                ans = (ans&a[i]);
            }
            cout<<ans<<endl;
            return 0;
        }
        if(m==n-1){
            dfs(0,1023);
            cout<<ans<<endl;
            return 0;
        }


        cout<<maxn;
    }

    return 0;
}
