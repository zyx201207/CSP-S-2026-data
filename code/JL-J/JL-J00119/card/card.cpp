#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001];
int st[300001];
int pos[300001],ans[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int top=0;
        memset(pos,0,sizeof(pos));
        for(int j=i;j<=n;j++){
            if(pos[a[j]]<=top&&pos[a[j]]>0){
                top=pos[a[j]]-1;
                st[++top]=a[j];
            }else{
                st[++top]=a[j];
                pos[a[j]]=top;
            }
            //cout<<i<<' '<<j<<' '<<top<<' '<<st[top]<<'\n';
        }
        for(int j=1;j<=top;j++){
            ans[st[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}
