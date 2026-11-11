#include<bits/stdc++.h>
using namespace std;

int m,n,ans[100005],a=0;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int a[n];
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    cout<<a[0];
    return 0;
}
