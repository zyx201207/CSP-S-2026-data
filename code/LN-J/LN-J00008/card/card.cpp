#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        long long card[n+5-i];
        long long tail=1;
        for(long long j=i;j<=n;j++){
            long long memcl=0;
            card[tail]=a[j];
            for(long long k=1;k<tail;k++){
                if(card[k]==card[tail]){
                    memcl=k;
                    break;
                }
            }
            if(memcl!=0){
                tail=memcl;
            }
            tail++;
        }
        for(long long j=1;j<tail;j++){
            ans[card[j]]++;
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
