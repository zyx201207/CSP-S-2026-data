#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=5e5+100;
ll n, m, a[MAXN], t[MAXN], sum, w, curn, ans;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a, a+n);
    for (int i=1;i<n;i++){
        t[i]=a[i]-a[i-1];
        sum+=t[i];
        curn++;
        w+=t[i]*curn;
        while(w>m){
            w-=sum;
            sum-=t[i-curn+1];
            curn--;
        }
        // printf("%d curn=%d w=%d\n", i, curn, w);
        ans=max(ans, curn+1);
    }
    cout<<ans<<endl;
    return 0;
}
