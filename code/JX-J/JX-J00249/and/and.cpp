#include<bits/stdc++.h>
using namespace std;
long long a[200009];
long long ans=0;
int n,m;
bool cmp(long long g,long long h){
    return g>h;
    }
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for(int i=1;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
return 0;
}
