#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,p,cnt;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            p=1;
            cnt=0;
            memset(b,0,sizeof(b));
            for(int k=j;k<=n;k++){
                b[p]=a[k];
                p++;
            }
            for(int i=1;i<=p;i++){
                if(b[i]==i){
                    cnt++;
                    break;
                }
            }
            cout<<cnt<<'\n';
        }
    }
    return 0;
}
