#include<bits/stdc++.h>
using namespace std;
long long int a[200010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1];
    if(m==1){
        cout<<ans;
        return 0;
    }
    for(int i=2;i<=m;i++){
        ans=a[i]&ans;
    }
    cout<<ans;
    return 0;
}
