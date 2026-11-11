#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int f;
int sum,minn;
int x[2000005];
long long a[2000005];
void dfs(int l,int cnt){
    if(l==f){
        if(cnt==minn)
        sum++;
        else if(cnt<minn)
            minn=cnt,sum=1;
        return;
    }
    if(sum>2)
        return;
    for(int i=l+1;i<=f;i++){
        if(a[i]-a[l]<=d)
            dfs(i,cnt+1);
        else
            break;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                f=j;
                sum=0;
                minn=1e9;
                dfs(i,0);
                if(sum==2)
                    ans++;
                if(sum>2)
                    break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
