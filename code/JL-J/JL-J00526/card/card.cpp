#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int sum[2000005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(a[i]==a[j]){
                    sum[a[j]]+=1;
                }else{
                    sum[a[j]]++;
                }
            }
        }
    //}

    for(int i=1;i<=m-1;i++){
        cout<<sum[i]-1<<" ";
    }
    cout<<sum[m];
    return 0;
}
