#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[510][3][3];
int bj[510][3];
int b[1010];
long long ans=0;
long long w=9999999;
int bjz;
void dfs(int ls,int lz){
    for(int i=1;i<=n;i++){
        if(a[i][1][1]==ls and bj[i][1]==0){
                ans+=b[i];
                ans+=a[i][1][2];
                bj[i][1]=1;
                bjz=a[i][1][1];
            dfs(a[i][2][1],lz);
        }
    }
     for(int i=1;i<=n;i++){
        if(a[i][2][1]==ls and bj[i][2]==0){
                 bj[i][2]=1;
                ans+=a[i][2][2];
                bjz=a[i][2][1];
            dfs(a[i][2][1],lz);
        }
    }
    w=min(w,ans);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c>> n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin >>b[i];
    }
    for(int i=1;i<=n;i++){
        int ff;
        cin >>ff;
        cin>>a[n][1][1];
        cin>>a[n][1][2];
        cin>>a[n][2][1];
        cin>>a[n][2][2];
    }
    for(int i=1;i<=q;i++){
        int xx,yy;
        cin >>xx>>yy;
        dfs(xx,yy);
        w+=b[bjz];
    cout << w<<endl;
        w=9999999;
        ans=0;
    }

    return 0;
}
