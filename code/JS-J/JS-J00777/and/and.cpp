#include <bits/stdc++.h>
using namespace std;
vector<unsigned int>va;
int f(){
    unsigned long long n;
    cin>>n;
    va.push_back(n);
    int ans=0;
    while(n>0){
        ans+=n%2;
        n/=2;
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    vector<pair<int,int>>a;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int s=f();
        a.push_back({s,i});
    }
    sort(a.begin(),a.end());
    long long l=a.size();
    l--;
    unsigned long long an=va[a[l].second];
    while(--l>1){
        an=an&va[a[l].second];
    }
    cout<<an;
    return 0;
}
