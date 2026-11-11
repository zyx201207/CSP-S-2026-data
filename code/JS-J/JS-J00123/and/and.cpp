#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1];
    for(int i=2;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
