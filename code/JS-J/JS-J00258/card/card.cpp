#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
bool rec[500005];
int ans[500005];
int b[300005];
int x;
int t;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        x=i;
        memset(rec,0,n+1);
        memset(b,0,n+1);
        t=1;
        while(x<=n){
            if(rec[a[x]]==false){
                rec[a[x]]=true;
                b[t++]=a[x];
            }
            else{
                while(b[t]!=a[x]) rec[b[t--]]=false;

                rec[a[x]]=true;
                b[t++]=a[x];
            }
            x++;
        }
        for(int i=1;i<=n;i++){
            if(rec[i]==true){
                ans[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
