#include<bits/stdc++.h>
using namespace std;
int a[20002];
int max1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n-1,greater<int>());
    max1=a[0];
    for(int i=1;i<m;i++){
        max1&=a[i];
    }
    cout<<max1;
    return 0;
}
