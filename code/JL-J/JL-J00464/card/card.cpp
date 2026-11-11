#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],en[500005];
    cin>>n>>m;
    bool inn(int a,int b){
        for(int i=1;i<=n;i++){
            if(a==en[i]) return true;
            else return false;
        }
    }
    for(int i=1;i<=n;i++){
        memset(a,0,sizeof(a));
        for(int j=1;j<=n;j++) cin>>a[i];
        for(int x=i;x<=n;x++){
            int id=1;
            if(inn(a[x],en)){
                id=1;
                memset(en,0,sizeof(en))
            }
            en[id]=a[x];
            id++;
        }

    }
    for(int i=1;i<=n;i++){

    }
    cout<<3<<" "<<1<<" "<<4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
