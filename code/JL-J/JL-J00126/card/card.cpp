#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
int a[N],b[N],c[N],cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            c[i]=a[i];
            b[a[i]]++;
            if(b[a[i]]==2){
                memset(c,0,sizeof(c));
                c[1]=a[i];
            }
        }
        for(int j=1;j<=n;j++){
            if(c[j]!=0) cnt[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
