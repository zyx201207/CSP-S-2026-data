#include<bits/stdc++.h>
using namespace std;
int c,m,q,n,d,ans;
int w[100005],xx[505];
int vis[100005];
struct Node{
    int k,t;
}a[505][500005];
int dfs(int s1,int s2,int rr){
        if(vis[s1]==1){
            return 0x3f3f3f3f;
        }
    if(s1==s2){
        return w[s1];
    }
    Node ss[d+1];
    int d1=1,d2=1,ds1[n+1][2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=xx[i];j++){
            if(a[i][j].k==s1){
                ss[d1]=a[i][j];
                ds1[d1][0]=i;
                ds1[d1][1]=j;
                d1++;
            }
        }
    }
    d1--;
    d2--;
    int mi=0x3f3f3f3f;
    for(int i=1;i<=d1;i++){
        vis[ss[i].k]=1;
        if(ds1[i][0]==rr || rr==0){
            mi=min(mi,dfs(a[ds1[d1][0]][ds1[d1][1]+1].k,s2,ds1[i][0]));
        }
        else{
            mi=min(mi,dfs(a[ds1[d1][0]][ds1[d1][1]+1].k,s2,ds1[i][0])+ss[i].t+a[ds1[d1][0]][ds1[d1][1]+1].t);
        }
        vis[ss[i].k]=0;
    }
    return mi;
}
int f2(int s1,int s2){
    if(vis[s1]){
        return 0x3f3f3f3f;
    }
    if(s1==s2){
        return w[s1];
    }
    Node ss[d+1];
    int d1=1,ds1[n+1];
    for(int i=1;i<=n;i++){
            if(a[i][1].k==s1){
                ss[d1]=a[i][1];
                ds1[d1]=i;
                d1++;
            }
    }
    d1--;
    int mi=0x3f3f3f3f;
    vis[s1]=1;
    for(int i=1;i<=d1;i++){
        mi=min(mi,f2(a[ds1[i]][2].k,s2)+a[ds1[i]][1].t+a[ds1[i]][2].t);
    }
    vis[s1]=0;
    return mi;
}
int f3(int s1,int s2,int rr){
        if(vis[s1]==1){
            return 0x3f3f3f3f;
        }
    if(s1==s2){
        return w[s1];
    }
    Node ss[d+1];
    int d1=1,d2=1,ds1[n+1][2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=xx[i];j++){
            if(a[i][j].k==s1){
                ss[d1]=a[i][j];
                ds1[d1][0]=i;
                ds1[d1][1]=j;
                d1++;
            }
        }
    }
    d1--;
    d2--;
    int mi=0x3f3f3f3f;
    for(int i=1;i<=d1;i++){
        vis[ss[i].k]=1;
        if(ds1[i][0]==rr || rr==0){
            mi=min(mi,dfs(a[ds1[d1][0]][ds1[d1][1]+1].k,s2,ds1[i][0]));
        }
        else{
            mi=min(mi,dfs(a[ds1[d1][0]][ds1[d1][1]+1].k,s2,ds1[i][0])+2*a[1][1].t);
        }
        vis[ss[i].k]=0;
    }
    return mi;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        xx[i]=x;
        for(int j=1;j<=2*x;j++){
            cin>>a[i][j].k>>a[i][j].t;
        }
    }
    while(q--){
            memset(vis+1,0,sizeof(vis));
        ans=0;
        int s1,s2;
        cin>>s1>>s2;
        if(c>=12 &&c<=19){
            ans=f3(s1,s2,0);
        }
        else if(c>=7 && c<=11){
            vis[s1]=1;
            ans=f2(s1,s2);
        }
        else{
            vis[s1]=1;
            ans=dfs(s1,s2,0);
        }
        ans+=w[s1];
        ans+=w[s2];
        cout<<ans<<endl;
    }
    return 0;
}

