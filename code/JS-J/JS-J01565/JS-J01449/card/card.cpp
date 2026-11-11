#include<bits/stdc++.h>
using namespace std;
int a[500005],m,cnt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int g=1;
    while(g<=n){
          for(int i=0;i<n;i++){
              for(int j=i+1;j<n;j++){
                  if(a[i]!=a[j]) cnt[a[j]]++;
                  else{
                      i=j+1;
                      cnt[a[i]]++;
                      for(int k=i+1;k<j;k++){
                          cnt[a[k]]--;
                      }
                      
                  }
              }
          }
          g++;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}