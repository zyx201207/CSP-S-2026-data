#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200001],maxand=-1,temp,ans;
bool cmp(long long LH,long long SS){
    return LH>SS;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    ans=a[0];
    for(int i=1;i<m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
