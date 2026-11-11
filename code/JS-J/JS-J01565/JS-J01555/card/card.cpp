#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[300005][2];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    for(long long k=0;k<n;k++){
        for(long long i=1+k;i<=n;i++){
            if(cnt[a[i]][1]!=0){
                for(long long j=cnt[a[i]][1];j<i;j++){
                    cnt[a[j]][1]=0;
                }
            }
            cnt[a[i]][1]=i;
        }
        for(long long i=1;i<=m;i++){
            if(cnt[i][1]!=0){
                cnt[i][1]=0;
                cnt[i][0]++;
            }
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<cnt[i][0]<<" ";
    }
    return 0;
}
