#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[300005],a[500005],sum[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(sum[a[j]]){
                int k=j;
                while(1){
                    sum[a[k]]--;
                    if(a[k]==a[j] && k!=j){
                        sum[a[k]]++;
                        cout << k <<' ';
                        break;
                    }
                    k--;
                }
            }
            sum[a[j]]++;
        }
        for(int j=1;j<=m;j++){
            if(sum[j]){
                ans[j]++;
                sum[j]=0;
            }
        }
    }
    cout << endl;
    for(int i=1;i<=m;i++){
        cout << ans[i] <<' ';
    }
    return 0;
}
