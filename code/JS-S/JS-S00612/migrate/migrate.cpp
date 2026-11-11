#include <bits/stdc++.h>

using namespace std;

long long c,t,x[2000010],h[2000010],sum=1,n,d,ans=0;;
void dfs(int x,int y,int step)
{
    if(x==y){
        h[sum]=step;
        sum++;
        return;
    }
    for(int i=1;i<=d;i++){
        if(x+i<=y){
            dfs(x+i,y,step+1);
        }
        else continue;
    }
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum=1;
                long long cnt=1,k=1;
                dfs(i,j,0);
                sort(h+1,h+sum+1);
                while(h[k]==0){
                    k++;
                }
                while(h[k+1]==h[k]){
                    cnt++;
                    k++;
                }
                if(cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
