#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    int n,m;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int ans=a[1];
    for(int i=2;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans<<endl;
    return 0;
}
