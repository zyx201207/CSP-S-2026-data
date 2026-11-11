#include <bits/stdc++h>
using namespace std;
int fn(int jl,vector<int> island,int d){
   ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t){
        int n,ans;
        int d;
        cin>>n>>d;
        vector<int> island(n);
        for(int i=0;i<n;i++){
            cin>>island[i];
        }
 //       for(int i=1;i<n;i++){
  //          if(fn(i,island,d)==2) ans++;
    //    }
        cout<<n-d-1<<endl;
        t--;
    }
    return 0;
}
