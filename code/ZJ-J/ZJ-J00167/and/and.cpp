#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int& i:a) cin>>i;
    vector<int> na;
    na.reserve(n);
    int res=0;
    for(int i=1<<29;i;i>>=1) {
        na.clear();
        for(int j:a) if(j&i) na.emplace_back(j);
        if(na.size()>=m) {
            res|=i;
            swap(a,na);
        }
    }
    cout<<res<<'\n';
}