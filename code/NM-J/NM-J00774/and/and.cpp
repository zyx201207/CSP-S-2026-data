#include <bits/stdc++.h>
using namespace std;
int main(){

ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,ans,f;
cin>>n>>m;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
        f=1;
    for(int j=0;j<n;j++){
        if(a[i]>a[j]&&f!=0){
            swap(a[i],a[j]);
            f=0;
        }
    }
}
ans=a[0];
for(int i=1;i<m;i++){
    ans=ans&a[i];
}
cout<<ans;
return 0;
}
