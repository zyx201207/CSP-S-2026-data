#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    frepon("crystal.in","r",stdin);
    frepon("crystal.out","w",stdout);
    int n,m,mi=INT_MAX,s=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    sort(a+1,a+1+n);
    while(m>0){
    for(int i=1;i<=n;i++){
     mi=min(mi,abs(a[n/2]-a[i]));
     }
     m-=mi;
     s++;
     }
     cout<<s;
     return 0;
} 
