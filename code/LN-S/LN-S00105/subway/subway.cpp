#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
int c,n,m,d,q,w[500010]={},k,a[500][500010]={},t[500][500010]={},x[100010]={},y[100010]={};
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    cin>>w[i];
}
for(int i=1;i<=n;i++){
        cin>>k;
    for(int j=1;j<=k;j++){
        cin>>a[i][j]>>t[i][j];
    }
}
for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
}
for(int i=1;i<=q;i++){
    for(int j=1;j<=n;j++){
            for(int z=1;z<=k[j];z++){
                if(a[j][z]==x[i]){
                       bool hf=0;
                while(hf){
        for(int s=)
                         }
                }
    }

}

fclose(stdin);
fclose(stdout);
return 0;
}
