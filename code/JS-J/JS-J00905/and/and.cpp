#include<bits/stdc++.h>
using namespace std;
int n,m,i,h;
int a[100000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
    }
   return 0;
}
