#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    return 0;
    int n,m,a[10010],t=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        a[i]+=1;
        if(a[j]==a[i]){
         t++;
         a[j]=a[i]+1;
        }
    }
   }
   cout<<t;
}
