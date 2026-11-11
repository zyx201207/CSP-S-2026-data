#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<string>b;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,an;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>an;
        a.push_back(an);
    }
    sort(a.begin(),a.end());
    cout<<a[n-m];

    return 0;
}
