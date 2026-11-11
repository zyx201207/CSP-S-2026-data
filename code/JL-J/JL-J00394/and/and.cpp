#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10010],b[10000010],maxa=INT_MIN,maxx=-1,maxax=-1;
void dfs(int d,int cnt,int sum,int a1){
    if(cnt==m){
        maxa=max(maxa,sum);
        return;
    }
    if(d==n+1) return;
    if(!a1) dfs(d+1,cnt+1,a[d],1);
    else if(a1){
        int a2=sum;
        a2&=a[d];
        dfs(d+1,cnt+1,a2,1);
    }
    dfs(d+1,cnt,sum,a1);
}
signed main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        sort(a+1,a+1+n);
        cout<<a[n];
    }
    else if(m==n){
        int cnt=a[1];
        for(int i=2;i<=m;i++) cnt&=a[i];
        cout<<cnt;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            b[a[i]]++;
            maxx=max(maxx,a[i]);
        }
        int res=-1;
        for(int i=1;i<=n;i++)
            if(b[i]>=2) res=b[i];
        if(res!=-1){
            cout<<res;
            return 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                maxax=max(maxax,a[i]&a[j]);
            }
        }
        cout<<maxax;
    }
    else if(m==n-1){
            int maxxx=-1,cnt=0;
        for(int i=1;i<=n;i++){
            i!=1?cnt=a[1]:cnt=a[2];
            for(int j=2;j<=n;j++){
                if(j==i) continue;
                cnt&=a[i];
            }
            maxxx=max(cnt,maxxx);
        }
        cout<<maxxx;
    }
    else{
        dfs(1,0,0,0);
        cout<<maxa;
    }
    return 0;
}
