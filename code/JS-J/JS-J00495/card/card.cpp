#include<bits/stdc++.h>
using namespace std;
int a[500009],que[300009],ans[300009];
bool b[300009];
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,top=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        memset(b,0,sizeof(b));
        top=0;
        for(int j=i;j<=n;++j){
            if(!b[a[j]]){
                que[++top]=a[j];
                b[a[j]]=true;
            }
            else{
                while(que[top]!=a[j]){
                    b[que[top--]]=false;
                }
            }
        }
        for(int j=1;j<=top;++j){
            ans[que[j]]++;
        }
    }
    for(int i=1;i<=m;++i){
        cout<<ans[i]<<" ";
    }
}
