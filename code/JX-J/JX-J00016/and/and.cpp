#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    vector<int> a[200003]={};
    int n,m;
    long long q;
    cin>>n>>m;
    if(m==1){
      for(int i=1;i<=n;i++){
          cin>>q;
          ans=max(ans,q);
      }
    }
    else if(m==2){
      for(int i=1;i<=n;i++){
        cin>>q;
        while(q!=0){
            a[i].push_back(q%2);
            q=q/2;
        }
      }
      for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int bj=min(a[i].size(),a[j].size());
            vector<int> sc;
            for(int k=0;k<=bj-1;k++){
                if(a[i][k]==1 and a[j][k]==1){
                    sc.push_back(1);
                }
               else{
                   sc.push_back(0);
               }
            }
            long long dw=1,jsq=0;
           for(int k=0;k<=sc.size()-1;k++){
              jsq=jsq+dw*sc[k];
              dw=dw*2;
           }
           ans=max(ans,jsq);
        }
      }
    }
    cout<<ans;
    return 0;
}
