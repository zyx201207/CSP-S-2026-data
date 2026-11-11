#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    freopen("and.in","r",stdin);freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    cout<<a[m-1];
    return 0;
}
