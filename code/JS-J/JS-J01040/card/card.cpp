#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=5e5;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(1){
            int q=1;
        for(int i=q;i<=n;i++){
            if(b[a[i]]==0){
                b[a[i]]=1;
            }else{
                for(int j=i;j>=1;j--){
                    b[j]=0;
                }
            }
        }
        for(int q=1;q<=n;q++){
             c[q]+=b[q];
        }
       q++;
    if(q==n){
        break;
        }
    }

    for(int i=1;i<=m;i++){
        cout<<c[i];
    }

    return 0;
}
