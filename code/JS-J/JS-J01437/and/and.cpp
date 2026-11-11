#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ans=1;
    vector<int> a;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        a.push_back(k);
    }
    sort(a.begin(),a.end(),cmp);
    ans=a[0]&a[1];
    for(int i=2;i<m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
