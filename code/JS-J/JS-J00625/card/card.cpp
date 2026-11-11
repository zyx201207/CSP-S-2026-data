#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,c;
    cin>>n>>m;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>c;
        a.push_back(c);
    }
    for(int i=1;i<=m;i++){
        cout<<a.size()<<' ';
    }
    return 0;
}
