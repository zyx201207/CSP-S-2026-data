#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long ans[300005];
long long b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=1;
    while(i<=n){
        int k=1;
        for(int j=i;j<=n;j++){
            b[k]=a[j];
            for(int o=i;o<=k;o++){
                if(a[o]==b[k]){
                    k=o;
                    break;
                }
            }
            k++;
        }

        k--;
        for(int j=1;j<=k;j++){

            ans[b[j]]++;
        }

        i++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}


