#include <bits/stdc++.h>
using namespace std;
int m,t,sum;
int main(){
   freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
   string n,t1;
   cin>>m;
    for(int i=1;i<=m;i++){
        cin>>t;
        cin>>t1;
        for(int k=1;k<=t;k++)
            n+=t1;
    }
    for(int j=0;j<=(n.size()/2-1);j++)
        if(n[j]!=n[n.size()-j-1])
            sum++;
    cout<<sum;
return 0;
}
