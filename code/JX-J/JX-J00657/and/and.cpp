#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans,ans2;
bool cmp(int x,int y){
    if(x%2==1&&y%2==1) return x>y;
    return x%2;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    sort(a+1,a+1+n);
    ans2=a[n];
    for(int i=n-1;i>n-m;i--){
        ans2&=a[i];
    }
    cout<<max(ans,ans2);
    return 0;
}
