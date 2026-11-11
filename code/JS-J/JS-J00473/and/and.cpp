#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> w(n);
    sort(w.begin(),w.end());
    int qq=w[n-1];
    for(int i=n-1;i>=n-m;i--){
        qq=qq&w[i];
    }
    cout<<qq;
    return 0;
}
