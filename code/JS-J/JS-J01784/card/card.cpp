#include<bits/stdc++.h>
using namespace std;
int n,m,tot=0;
int a[200005],b[200005];
int js[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //check this before you submit!

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        tot++;
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            a[i]=b[i];
        }
        for(int i=k;i<=n;i++){
            int op=b[i];
            bool tf=false;
            for(int j=k;j<=tot;j++){
                if(a[j]==op){
                    tot=j;
                    tf=true;
                    break;
                }
            }
            if(!tf){
                a[++tot]=op;
            }
        }
        for(int i=k;i<=tot;i++){
            js[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<js[i]<<' ';
    }
    return 0;
}
