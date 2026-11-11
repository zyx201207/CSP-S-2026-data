#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[1005],dp[1005];
    cin>>n>>m;
    int maxn = 0;
    for(int i = 1; i<= n; i++){
        cin>>a[i];
        maxn = max(maxn,int(a[i]));
    }
    int maxx = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if((a[i]&a[j]) > maxx){
                if(i!=j){
                    maxx = (a[i]&a[j]);
                }
            }
        }

    }
    if(m == 1){
       cout<<maxn;
    }else if(m == 2){
        cout<<maxx;
    }

    return 0;
}
