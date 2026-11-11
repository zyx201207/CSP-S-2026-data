#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;

int n,m;
vector<int> a;


int main(){
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        a.push_back(l);
    }
    sort(a.begin(),a.end());
    int ans=a[n-1];
    for(int i=1;i<m;i++){
        //cout<<ans<<"ad"<<a[n-i-1]<<"\n";
        //cout<< (ans&12);
        ans=ans&a[n-i-1];

    }
    cout<<ans;

    return 0;
}
