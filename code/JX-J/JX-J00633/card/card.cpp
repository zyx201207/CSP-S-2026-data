#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[500010],ans[300010],vis[300010],flag[500010];
int dg(int c){
    if(c==n+1){
        return 0;
    }
    for(int i=c;i<=n;i++){
        if(vis[a[i]]){
            ans[a[i]]--;
            flag[i]=1;
            vis[a[i]]=0;
            for(int j=i-1;j>=1;j--){
                if(a[j]==a[i] && flag[j]==0) break;
                if(flag[j]==0){
                    ans[a[j]]--;
                    vis[a[j]]=0;
                    flag[j]=1;
                }
            }
        }
        vis[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        flag[i]=0;
    }
    for(int i=1;i<=m;i++){
        vis[i]=0;
    }
    return dg(c+1);

}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=n;i>=1;i--){
        ans[a[i]]+=i;
    }

    dg(1);

    for(int i=1;i<=m;i++){
        cout << ans[i] << ' ';
    }




    return 0;
}
