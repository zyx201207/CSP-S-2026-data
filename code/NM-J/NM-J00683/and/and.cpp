#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
vector<ll>a;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll t;cin>>t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    cout<<a[n-m]<<endl;
    return 0;
}
