#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,r;
int w[500005],f[1000000000];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>n>>m>>d>>q;
for(int i-1;i<=m;i++){
    cin>>w[i];
}
memset(f,0x3f,sizeof(f));
for(int i=1;i<=n;i++){

}
for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
}
while(q--){
    int x,y;
    cin>>x>y;
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
