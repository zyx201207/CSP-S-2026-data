#include<bits/stdc++.h>
#define iwill using
#define ak namespace
#define cspj std;
iwill ak cspj
int n,m,a[300005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int an=a[n];
    for(int i=n-1,j=2;j<=m;j++,i--){
        an=an&a[i];
    }
    cout<<an<<endl;
    return 0;
}
