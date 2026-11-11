#include<bits/stdc++.h>
using namespace std;
int n,m,tot;
const int MAXN=2e5+5;
int nex[2][32],a[MAXN],cnt[2][32],ans;
void init(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            int k=30-j;
            int c=(1<<k);
            c&=a[i];
            c=c>>k;
            cnt[c][j]++;
            if(!nex[c][j]){
                nex[c][j]=++tot;
        }
    }
    tot=0;
    }
}
int main(){
   //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    init();
    cout<<ans;
    return 0;
}
