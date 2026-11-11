#include <bits/stdc++.h>

using namespace std;
int n,d,a[2000006];
int cnt[100];
void dfs(int s,int e,int p,int l){
    if(p==e){cnt[l]++;return ;}
    for(int i=p+1;a[i]-a[p]<=d&&i<=e;i++){
        dfs(s,e,i,l+1);
    }return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n<500){
            int ans=0;
            for(int i=1;i<n-2;i++){
                for(int j=i+3;j<=n;j++){
                    memset(cnt,0,sizeof(cnt));
                    dfs(i,j,i,0);
                    for(int k=0;k<n;k++){
                        if(cnt[k]==0)continue;
                        else {
                            if(cnt[k]==2)ans++;
                            break;
                        }
                    }
                }
            }cout<<ans<<endl;
        }
        else{
            int l=d/(a[2]-a[1]);
            cout<<max(n-(l+l-1),0)<<endl;;
        }
    }
    return 0;
}
