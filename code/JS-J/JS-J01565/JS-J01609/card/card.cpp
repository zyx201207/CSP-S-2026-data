#include<bits/stdc++.h>
using namespace std;
int n,m,a[600001],id[500001],ans[500001];
int ok[500001],l,c[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(ok,0,sizeof(ok));
        memset(c,0,sizeof(c));
        l=0;
        for(int j=i;j<=n;j++){
            if(!ok[a[j]]){
                c[++l]=a[j];
                ok[a[j]]=l;
            }
            if(ok[a[j]]){
                if(c[ok[a[j]]]==a[j]&&ok[a[j]]<=l){
                    l=ok[a[j]];
                }
                else{
                    c[++l]=a[j];
                }
                ok[a[j]]=l;
            }
            //for(int j=1;j<=l;j++){
            //    cout<<c[j]<<' ';
            //}
            //cout<<"\n"<<"\n";
        }
        for(int j=1;j<=l;j++){
            ans[c[j]]++;
            //cout<<c[j]<<' ';
        }
        //cout<<"\n";
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}
