#include <bits/stdc++.h>
using namespace std;
int a[1000005],f[1000005],cnt[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int j=1,k=1;
    while(k<=n){
        f[j]=a[j];
        j++;
        for(int i=1;i<j;i++){
            if(f[i]==f[j-1]){
                for(int b=i;b<j-1;b++){
                    f[b]=0;
                }
                break;
            }
        }
        if(j>n){
            for(int i=1;i<=n;i++){
                cnt[f[i]]++;
            }
            memset(f,0,sizeof(f));
            j=0;
            k++;
            j+=k;
        }
    }for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
