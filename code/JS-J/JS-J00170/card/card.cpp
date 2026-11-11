#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500000+5],cnt[300000+5];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    long long las=0;
    for(int i=1;i<=3000005;i++){
        if(cnt[i]==0){
            continue;
        }
        cout<<cnt[i]+las<<" ";
        las+=cnt[i];
    }
    return 0;
}
