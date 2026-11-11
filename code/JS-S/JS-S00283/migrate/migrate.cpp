#include<bits/stdc++.h>
#define ll long long
using namespace std;
int C,T,n,l[2000005],r[2000005];
ll ans,d,a[2000005],l1,l2,r1,r2,v;
bool vis[5005][5005];
queue<ll>q;
void solve1(){
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)vis[i][j]=false;
    for(int i=1;i<n;i++)vis[i+1][i]=true;
    for(int i=1;i<=n-3;i++){
        for(int j=i+3;j<=n;j++){
            if(r[i]<l[j]&&l[j]!=j&&r[i]!=i&&(vis[r[i]][l[j]]||vis[i][l[j]]||vis[r[i]][j]))vis[i][j]=true,ans++;
            else if(r[i]-l[j]==1)vis[i][j]=true,ans++;
        }
    }
}
void solve2(){
    if(d>=a[3]-a[1]&&d<a[4]-a[1])ans=n-3;
}
void solve3(){
    l1=r1=l2=r2=0;
    for(int i=1;i<=n;i++)if(l[i]==1&&r[i]==n)v=i;
    for(int i=1;i<v;i++){
        if(r[i]==v)l1++;
        else if(r[i]==v+1)l2++;
    }
    for(int i=1;i<v;i++){
        if(l[i]==v)r2++;
        else if(r[i]==v-1)r1++;
    }
    ans=l1*r1+l2*r2;
}
int main(){
    freopen("migrate3.in","r",stdin);
    freopen("migrate3.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)l[i]=r[i]=0;
        for(int i=1;i<=n;i++){
            while(q.size()&&a[i]-a[q.front()]>d){
                r[q.front()]=i-1;
                q.pop();
            }
            q.push(i);
        }
        while(q.size()){
            r[q.front()]=n;
            q.pop();
        }
        for(int i=n;i>=1;i--){
            while(q.size()&&a[q.front()]-a[i]>d){
                l[q.front()]=i+1;
                q.pop();
            }
            q.push(i);
        }
        while(q.size()){
            l[q.front()]=1;
            q.pop();
        }
        if(C<=10)solve1();
        else if(C<=12)solve2();
        else if(C<=14)solve3();
        else ans=0;
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
