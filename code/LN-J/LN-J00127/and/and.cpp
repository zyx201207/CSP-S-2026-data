#include<bits/stdc++.h>
using namespace std;
bool px(int n,int m){
    return n>m;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,px);
    int cnt=a[0];
    for(int i=1;i<n;i++){
        cnt=cnt&a[i];
    }
    cout<<cnt;
    return 0;
}
