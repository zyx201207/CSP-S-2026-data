#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
void f1(){
    int ans[205]{};
    for(int i=1;i<=n;i++){
        int b[505]{},s=0;
        for(int j=i;j<=n;j++){
            bool bol=0;
            for(int k=1;k<=s;k++){
                if(b[k]==a[j]){
                    bol=1;
                    break;
                }
            }
            if(bol==1){
                for(int k=s;k>=1;k--){
                    int tt=b[k];
                    b[k]=0;
                    s--;
                    if(tt==a[j]) break;
                }
            }
            s++,b[s]=a[j];
        }
        for(int j=1;j<=s;j++){
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
void f2(){
    int ans[3005]{};
    for(int i=1;i<=n;i++){
        int b[5005]{},s=0;
        for(int j=i;j<=n;j++){
            if(b[s]!=a[j]) s++,b[s]=a[j];
        }
        for(int j=1;j<=s;j++){
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=500) f1();
        else f2();
    return 0;
}
