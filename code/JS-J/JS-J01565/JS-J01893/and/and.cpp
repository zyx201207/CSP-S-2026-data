#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
int n,m;
int ans = -1;
int a[MAXN];
int s1[MAXN];
int s2[MAXN];
int c[21];
bool cmp(const int &x,const int &y){
    return x>y;
}
void dfs(int x,int res){
    if(x==m+1){
        ans = max(ans,res);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(c[i]) continue;
        c[i] = 1;
        dfs(x+1,res&a[i]);
        c[i] = 0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=20){
        memset(c,0,sizeof(c));
        dfs(1,INT_MAX);
        printf("%d\n",ans);
        return 0;
    }
    if(n<=2000&&m==1){
        for(int i=1;i<=n;i++){
            ans = max(ans,a[i]);
        }
        printf("%d\n",ans);
        return 0;
    }
    if(n<=2000&&m==n){
        ans = INT_MAX;
        for(int i=1;i<=n;i++){
            ans &= a[i];
        }
        printf("%d\n",ans);
        return 0;
    }
    if(n<=2000&&m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                ans = max(ans,a[i]&a[j]);
            }
        }
        printf("%d\n",ans);
        return 0;
    }
    if(n<=2e5&&m==n-1){
        s1[0] = INT_MAX;
        for(int i=1;i<=n;i++){
            s1[i] = s1[i-1] & a[i];
        }
        s2[n+1] = INT_MAX;
        for(int i=n;i>=1;i--){
            s2[i] = s2[i+1] & a[i];
        }
        ans = max(s2[2],s1[n-1]);
        for(int i=2;i<=n-1;i++){
            ans = max(ans,s1[i-1]&s2[i+1]);
        }
        printf("%d\n",ans);
        return 0;
    }else{
        sort(a+1,a+n+1,cmp);
        printf("%d\n",a[m]);
    }
    return 0;
}