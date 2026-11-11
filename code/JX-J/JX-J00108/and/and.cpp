#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;
long long ans=0;
int a[maxn];
int main(){
     freopen("and.in","r",stdin);
     freopen("and.out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=n;i++){
        cin>>a[i];
     }
     long long num;
     for(int i=1;i<=n;i++){
          num=a[i];
     for(int j=1;j<m;j++){
        num=num&a[i+j];
     }
        ans=max(ans,num);
     }
     sort(a+1,a+n+1);
     for(int i=1;i<=n;i++){
          num=a[i];
     for(int j=1;j<m;j++){
        num=num&a[i+j];
     }
        ans=max(ans,num);
     }
     cout<<ans;
    return 0;
}
