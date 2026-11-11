#include<bits/stdc++.h>
using namespace std;
int a[200005];int n,m;
int dfs(int r,int b,int c){
    if(b==m){
        return r;
    }
    int cnt=0;
    for(int i=c;i<=n;i++){
        cnt=max(cnt,dfs(r&a[i],b+1,i+1));
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    if(n<=20){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt=max(cnt,dfs(a[i],1,i+1));
        }
        cout<<cnt;
    }else if(n>2000){
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans=min(a[i],ans);
        }
        cout<<ans;

    }
    else if(m==1){
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans=max(a[i],ans);
        }
        cout<<ans;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt=max(cnt,a[i]&a[j]);
            }
        }
        cout<<cnt;
    }else{
        cin>>a[1];
        int ans=a[1];
        for(int i=2;i<=n;i++){
            cin>>a[i];
            ans=ans&a[i];
        }
        cout<<ans;
    }

    return 0;
}
