//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ma=0;
int a[20000];
int n,m;
//int
int maai=0;
void dfs(int i,int he,int k){//cha di i ge dangqianhewei m,yixuan k ge;
    if(k==m)
    {
        ma=max(ma,he);
        return ;
    }
    if(i==n+1||he<ma){
        return ;
    }
    /*if(k+n-i+1<m){
        return ;
    }*/

    dfs(i+1,he&a[i],k+1);
    dfs(i+1,he,k);
}
int islog(int x){
    while(x%2==0){
        x/=2;
    }
    if(x==1){
        return 1;
    }
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //cin>>n>>m;
    scanf("%d%d",&n,&m);

    int huo=(1<<29)-1;
    int isloo=1;
    for(int i=1;i<=n;i++){
        //cin>>a[i];
        scanf("%d",&a[i]);
        maai=max(maai,a[i]);
        huo=huo&a[i];
        isloo&=islog(a[i]);
    }
    if(m==n){
        cout<<huo;
        return 0;
    }

    dfs(1,(1<<29)-1,0);
    cout<<ma;
    //int f[n][m];
    //int f[maai*5][m*3+1];

    //f[0][(1<<21)+1][0]=(1<<21)+1;
    //f[0][0][0]=(1<<21)-1;
    /*for(int i=1;i<=n;i++){
        f[i][a[i]][1]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=maai;j>=0;j--){
            //f[j][i]=max(f[j][i],f[j])
            for(int k=0;k<m;k++){
                if(f[i][j][k]==0)continue;

                f[i+1][j&a[i+1]][k+1]=1;
                f[i+1][j][k]=1;
                //cout<<f[i][j][k]<<" ";
            }


    for(int i=maai;i>=0;i--){
        if(f[n][i][m]!=0){
            cout<<i;
            return 0;
        }

    }*/
    /*int ma=0;
    for(int i=0;i<=maai;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        f[a[i]][1]=i;
    }
    f[0][0]=(1<<30)-1;
    for(int k=1;k<=n;k++){
        for(int i=maai;i>=0;i--){
            for(int j=0;j<=m;j++){
                if(j==m){
                    ma=max(ma,i);
                    continue;
                }
                if(f[i][j]&&k!=f[i&a[k]][j+1]){
                    cout<<i<<" "<<j<<" "<<k<<" "<<f[i&a[k]][j+1]<<endl;
                    f[i&a[k]][j+1]=k;
                    //cout<<f[i][j]<<i&a[k]<<j+1<<i<<j<<endl;
                    //cout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }
    cout<<ma;*/
    return 0;
}
