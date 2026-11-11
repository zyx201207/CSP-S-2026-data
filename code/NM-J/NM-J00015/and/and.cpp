#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int maxn = 2e5+10;
int n,m;
ll a[maxn],evn[maxn];
ll ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);

    //cout<<a[1]<<" "<<a[2]<<"\n";
    int j = 2;
    int cnt = 1;
    ans = a[1];
    for (int j=2;j<=n;j++){
        for (int i=31;i>=1;i--){
            if (a[j]&(1<<(i-1))){
                ans &= a[j];
                cnt ++;
                break;
            }
        }
        if (cnt == m) break;
    }
    /*for (int i=1;i<=n;i++){
        for (int j=31;i>=1;i--){
            if (a[i]&(1<<(j-1))){
                evn[j]++;
            }
        }
    }*/
    cout<<ans<<"\n";
    return 0;
}
