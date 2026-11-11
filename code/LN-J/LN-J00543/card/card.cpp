#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int c[500005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int k,r=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            k=a[j];
            if (b[k]==0){
                c[r]=k;
                b[k]=r;
                r++;

            }
            else{
                for(int h=b[k]+1;h<=r;h++){
                    b[c[h]]=0;
                    c[h]=0;
                }
                r=b[k]+1;
            }
            if (j==n){
                for(int h=1;h<=m;h++){

                    if(b[ans[h]]!=0){
                        ans[h]++;

                    }
                }
                for(int h=1;h<=n;h++){
                    c[h]==0;
                }
                for(int h=1;h<=m;h++){
                    b[h]==0;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }

    return 0;
}

