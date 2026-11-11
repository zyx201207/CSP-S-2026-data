#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=5e5+5, inf=1e9;
ll lst[N], qian[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    ll m, res;
    int l, r, mid, rec, ans=0;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>lst[i];
    }
    sort(lst+1, lst+n+1);
    for(int i=1; i<=n; i++){
        qian[i]=qian[i-1]+lst[i];
    }
    for(int i=1; i<=n; i++){
        l=1, r=i, rec=inf;
        while(l<=r){
            mid=(l+r)/2;
            res=lst[i]*(i-mid+1)-(qian[i]-qian[mid-1]);
            if(res<=m){
                rec=min(rec, mid);
                r=mid-1;
            }else l=mid+1;
        }
        ans=max(ans, i-rec+1);
    }
    cout<<ans;
    return 0;
}
