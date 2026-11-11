#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    vector<int>v(10000);
    vector<int>v1(10000);
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>v[i];
    }
    cout<<v[a-1];
    return 0;
}
