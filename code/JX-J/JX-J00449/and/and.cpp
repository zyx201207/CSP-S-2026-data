#include<bits/stdc++.h>
using namespace std;

int f(int a){
    int ans=0;
    while(a>0){
        ans+=(a&1);
        a>>=1;
    }
    return ans;
}

bool cmp(const int &a,const int &b){
    return a>b;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out"."w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),cmp);
    int ans=a[0];
    for(int i=1;i<m;i++){
        ans&=a[i];
    }
    cout<<ans<<'\n';
    return 0;
}
