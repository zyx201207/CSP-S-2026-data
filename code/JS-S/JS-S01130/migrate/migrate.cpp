
#include<bits/stdc++.h>
using namespace std;

int n,c,t,d;

struct s{
    int far,to[200005];
}a[200005];
void dfs(int f,int l,int now){
    if(now==l) {a[f].to[l]++;return;}
    int sum=a[now].far+d;
    for(int i=now+1;i<=n;i++) if(a[i]<=sum) dfs(f,l,i);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        long long to1[200005];
        for(int i=1;i<=n;i++) cin>>a[i].far;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dfs(i,j,i);
            }
        }
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[i].to[j]==2) ans++;
        cout<<ans<<endl;
    }



return 0;



}
