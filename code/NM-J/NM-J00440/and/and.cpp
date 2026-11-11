#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    if(m==1){
        cout<<a[0];
        return 0;
    }
    int ans=a[0];
    for(int i=1;i<m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
