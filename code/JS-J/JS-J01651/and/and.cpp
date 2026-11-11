#include<bits/stdc++.h>
using namespace std;
bool bi(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==n){
        int ans=a[0];
        for(int i=0;i<n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    sort(a.begin(),a.end(),bi);
    if(m==1){
        cout<<a[0];
        return 0;
    }
    int r=a[0];
    for(int i=1;i<m;i++){
        r&=a[i];
    }
    cout<<r;
    return 0;
}
