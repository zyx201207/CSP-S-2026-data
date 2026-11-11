#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        int x[500005]={0},s=0;
        for(int j=i;j<=n;j++){
            int f=1;
            for(int k=1;k<=s;k++){
                if(x[k]==a[j]) f=0;
                if(f==0){
                    x[k]=0;
                    s--;
                }
            }
            if(f==1){
                s++;
                x[s]=a[j];
            }
        }
        for(int j=1;j<=s;j++)
            b[x[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<b[i]<<' ';
    return 0;
}
