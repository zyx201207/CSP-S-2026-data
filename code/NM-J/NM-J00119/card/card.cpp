#include<bits/stdc++.h>
using namespace std;

int a[500005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
            int k=1;
        for(int j=i;j<=n;j++){
            b[k]=a[j];
            k++;
            for(int l=1;l<k;l++){
                if(b[l]==a[j]){
                    for(int x=l;x>=1;x++) b[x]=0;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(b[i]==0) continue;
        cout << b[i] << ' ';
    }
    return 0;
}
