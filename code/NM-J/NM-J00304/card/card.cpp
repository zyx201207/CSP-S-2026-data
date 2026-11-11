#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[500005],ans[500005],b[500005],c[500005];
int main(){
    //4 3
    // 1 4 1 3
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for (int q = 1;q<=n;q++){
        int k = 1;
        for (int i = q;i<=n;i++){

            b[k] = a[i];
            if (c[a[i]]==0) c[a[i]]++;
            else {
                b[k]=0;
                k--;
                while(b[k] != a[i]){
                    b[k] = 0;
                    k--;
                }
                c[a[i]] = 1;
            }
            k++;
        }
        for (int i = 1;i<=k;i++){
            cout<<b[i]<<' ';
            ans[b[i]]++;
        }
        cout<<endl;
    }
    for (int i = 1;i<=m;i++){
        //cout<<ans[m]<<' ';
    }
    return 0;
}
