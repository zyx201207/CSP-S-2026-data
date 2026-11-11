#include <bits/stdc++.h>
using namespace std;
int n,m,a[5555],ans[5555],v[5555],head,tail;
bool b[5555];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        memset(b,0,sizeof(b));
        head=0,tail=0;
        for(int j=i;j<=n;j++){
            int x=a[j];
            for(int k=head;k<tail;k++){
                if(v[k]==x){
                    tail=k+1;
                    break;
                }
            }
            v[tail++]=x;
        }
        for(int j=head;j<tail;j++){
            if(b[v[j]]==0){
                ans[v[j]]++;
                b[v[j]]=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}
