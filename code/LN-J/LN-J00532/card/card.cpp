#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int n,m,l=1,a[N],b[N],cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        int s=n-i+1;
        for(int j=i;j<=n;j++){
            for(int k=1;k<=s;k++){
                b[k]=a[j];
                for(int t=1;t<=k-1;t++){
                    if(b[t]==b[k]){
                        for(int ii=t;ii<=k-1;ii++){
                            b[ii]=0;
                        }
                    }
                }
            }
        }
        for(int j=1;j<=m;j++){
            for(int k=1;k<=s;k++){
                if(b[k]==j){
                    cnt[j]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
