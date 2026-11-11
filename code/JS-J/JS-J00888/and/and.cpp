#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long int n,m;
int a[N];
int vis[N];
int ans=-100;
void dfs(int i,int cnt,int cishu){
    if(cishu==0){
        if(ans<cnt)ans=cnt;
        return;
    }
    vis[i]=1;
    for(int x=0;x<n;x++){
        if(vis[x]==1)continue;
        dfs(x,cnt&a[i],cishu-1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        int maxn=-100;
        for(int i=0;i<n;i++){
            if(maxn<a[i])maxn=a[i];
        }
        cout<<maxn;
    }else if(m==n){
        int cnt=a[0];
        for(int i=1;i<n;i++){
            cnt=cnt&a[i];
        }
        cout<<cnt;
    }else if(m==2){
        int maxn=-100;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int kkk=a[i]&a[j];
                if(kkk>maxn)maxn=kkk;
            }
        }
        cout<<maxn;
    }else if(m==n-1){
        int maxn=-100;
        for(int i=0;i<n;i++){
            int cnt=a[0];
            if(i==0)cnt=a[1];
            for(int j=0;j<n;j++){
                if(j==i)continue;
                cnt=cnt&a[j];
            }
            if(cnt>maxn)maxn=cnt;
        }
        cout<<maxn;
    }else{
        for(int i=0;i<n;i++){
            dfs(i,a[i],m);
        }
        cout<<ans;
    }
    return 0;
}
