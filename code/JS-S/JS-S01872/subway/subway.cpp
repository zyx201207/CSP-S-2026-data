#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,tim,pos,k,x,y;
bool flag=0;
int w[500005];
int a[3][500005];
bool check(int x,int y,int z){
    if(a[z][x]!=0 && a[z][y]!=0) return true;
    return false;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>pos>>tim;
            a[i][pos]=tim;
        }
    }
    for(int k=1;k<=q;k++){
        cin>>x>>y;
        int sum=2000000005;
        for(int i=1;i<=n;i++){
            if(check(x,y,i)==1){
                sum=min(a[i][x]+a[i][y],sum);
            }
        }
        for(int i=1;i<=m;i++){
            if(check(x,i,1) && check(y,i,2)) sum=min(a[1][i]+a[2][i]+a[1][x]+a[2][y],sum);
            if(check(x,i,1) && check(y,i,3)) sum=min(a[1][i]+a[3][i]+a[1][x]+a[3][y],sum);
            if(check(x,i,2) && check(y,i,3)) sum=min(a[2][i]+a[3][i]+a[2][x]+a[3][y],sum);
            if(check(x,i,2) && check(y,i,1)) sum=min(a[1][i]+a[2][i]+a[2][x]+a[1][y],sum);
            if(check(x,i,3) && check(y,i,1)) sum=min(a[1][i]+a[3][i]+a[3][x]+a[1][y],sum);
            if(check(x,i,3) && check(y,i,2)) sum=min(a[2][i]+a[3][i]+a[3][x]+a[2][y],sum);
        }
        cout<<sum+w[x]+w[y]<<endl;
    }
    return 0;
}


