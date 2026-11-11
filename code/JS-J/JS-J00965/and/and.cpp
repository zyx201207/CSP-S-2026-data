#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int l[n+1];
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    sort(l+1,l+n+1);
    cout<<l[n+1-m];
    return 0;
}
