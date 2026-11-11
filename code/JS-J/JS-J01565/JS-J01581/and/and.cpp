#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=-1;
int a[200010],box[200010];
bool vis[200010];
struct node{
    int val;
    int cnt;
}z[200010];
int f(int x){
    int number=0;
    while(x){
        number+=x%2;
        x/=2;
    }
    return number;
}
bool cmp(node x,node y){
    return x.cnt>y.cnt;
}
void dfs(int k,int sum){
    if(sum==m){
        long long num=a[1];
        for(int i=2;i<=m;i++){
                num=num&box[i];
        }
        ans=max(ans,num);
        return;
    }
    for(int i=k;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        box[sum+1]=a[i];
        dfs(i+1,sum+1);
        vis[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.in","w",stdout);
    memset(box,-1,sizeof(box));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int maxn=-1;
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }
    if(m==n){
        long long res=a[1];
        for(int i=2;i<=n;i++)res=(long long)a[i]&res;
        cout<<res;
        return 0;
    }
    if(n<=5000&&m==2){
        long long maxn=-1;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,(long long)a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n-1){
        long long maxn=-1;
        for(int i=1;i<=n;i++){
            long long res=-1;
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                if(res==-1)res=a[j];
                else res=res&a[j];
            }
            maxn=max(maxn,res);
        }
        cout<<maxn;
        return 0;
    }
    if(n<=20){
        dfs(1,0);
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        z[i].val=a[i];
        z[i].cnt=f(a[i]);
    }
    sort(z+1,z+n+1,cmp);
    ans=z[1].val;
    for(int i=2;i<=m;i++){
        ans=ans&z[i].val;
    }
    cout<<ans;
    return 0;
}
