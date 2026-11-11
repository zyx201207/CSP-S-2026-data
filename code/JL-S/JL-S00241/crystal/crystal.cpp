#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long n,m,a[N],st[10005][10005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            st[i][j] = a[i] - a[j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int kk = j + 1;kk <= n;kk++){
                if(st[i][j] > st[i][kk]){
                    swap(st[i][j],st[i][kk]);
                }
            }
        }
        long long cum = m,sum = 1;
        for(int j = 1;j <= n;j++){
            if(st[i][j] < 0) continue;
            if(cum < st[i][j]){
                break;
            }
            cum -= st[i][j];
            sum++;
        }
        sum--;
        ans = max(ans,sum);
    }
    cout<<ans;
    return 0;
}
