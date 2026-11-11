#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ls[500005],ls2[500005],ls3[300005];
inline int suanshu(int x){
    int sum=0
    int fg=x;
    for(int i=n;i>fg;i--){
        if(ls[i]==ls[fg]){
            fg=i;i=n;
            ls2[sum++]=fg;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;//3 1 2 1 3 2 1 3 1 3
    for(int i=1;i<=n;i++){
        cin>>ls[i];
    }
    for(int i=1;i<=n;i++){
        suanshu(i);
    }
    return 0;
}