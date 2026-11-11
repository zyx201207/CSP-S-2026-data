#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],cnt,c[500005],d,k;
bool b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            k=a[j];
            if(!b[k]){
                b[k]=true;
                d+=1;
                c[d]=k;
            }
            else{
                d+=1;
                while(true){
                    d-=1;
                    if(c[d]==k){
                        break;
                    }
                    b[c[d]]=0;
                }
            }
        }
        d=0;
        for(int j=1;j<=m;j++){
            if(b[j]){
                ans[j]+=1;
            }
        }
        for(int j=1;j<=m;j++){
            b[j]=false;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}
