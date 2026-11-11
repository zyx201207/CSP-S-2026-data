#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,m,a[MAXN],f[21][21],ans,pre[MAXN],suf[MAXN],mx,sum[4];
bool A=1,B=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];mx=max(mx,a[i]);
        if((a[i]&(a[i]+1))!=0) A=0;
        if(a[i]!=i-1) B=0;
    }
    if(n<=20){
        f[0][0]=(1<<30)-1;ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(i,m);j++){
                for(int k=0;k<i;k++) f[i][j]=max(f[i][j],f[k][j-1]&a[i]);
            }
            ans=max(ans,f[i][m]);
        }
        cout<<ans<<"\n";
        return 0;
    }
    if(n<=2000){
        ans=0;
        if(m==1){
            for(int i=1;i<=n;i++) ans=max(ans,a[i]);
            cout<<ans<<"\n";return 0;
        }
        else if(m==2){
            for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
            cout<<ans<<"\n";return 0;
        }
        else if(m==n){
            ans=(1<<30)-1;
            for(int i=1;i<=n;i++) ans&=a[i]; 
            cout<<ans<<"\n";return 0;
        }
    }
    if(A){
        ans=(1<<30)-1;priority_queue<int> Q;while(!Q.empty()) Q.pop();
        for(int i=1;i<=n;i++) Q.push(a[i]);
        for(int i=1;i<=m;i++) ans&=Q.top(),Q.pop();
        cout<<ans<<"\n";
        return 0;
    }
    if(m==n-1){
        pre[0]=suf[n+1]=(1<<30)-1;ans=0;
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]&a[i];
        for(int i=n;i>=1;i--) suf[i]=suf[i+1]&a[i];
        for(int i=1;i<=n;i++) ans=max(ans,pre[i-1]&suf[i+1]);
        cout<<ans<<"\n";
        return 0;
    }
    if(mx<4){
        ans=0;
        for(int i=1;i<=n;i++) sum[a[i]]++;
        if(sum[3]>=m) ans=3;
        else if(sum[2]+sum[3]>=m) ans=2;
        else if(sum[1]+sum[3]>=m) ans=1;
        else ans=0;
        cout<<ans<<"\n";
        return 0;
    }
    if(B&&(n&(n-1))==0){
        int k=ceil(log2(m));
        ans=n-(1<<k);
        cout<<ans<<"\n";
        return 0;
    }
    return 0;
}