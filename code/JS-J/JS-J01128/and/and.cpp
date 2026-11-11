#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long vis[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= m;i++){
        vis[i] = 1;
    }
    sort(vis + 1,vis + n + 1);
    long long mx = 0;
    do{
        long long sum = 0;
        for(int i = 1;i <= n;i++){
            if(vis[i] == 1){
                if(sum == 0){
                    sum = a[i];
                }
                else{
                    sum &= a[i];
                }
            }
        }
        mx = max(mx,sum);
    }while(next_permutation(vis + 1,vis + n + 1));
    cout<<mx;
    return 0;
}
