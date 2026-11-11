#include<bits/stdc++.h>
using namespace std;
struct st{
      int x,y,z;
      bool operator<(st &w){
          return z<w.z;
      }
};
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
        int n,m,i,x,y;
        long long ans=0;
        cin>>n>>m;
        st a[n];
        for(i=0;i<n;i++)
             cin>>a[i].x>>a[i].y>>a[i].z;
             sort(a,a+n);
             int b[m+1];
             for(i=0;i<=m;i++){
                cin>>b[i];
             }
             for(i=0;i<n;i++){
                for(x=a[n].x;x!=b[x];x=b[x]);
                for(y=a[n].y;y!=b[y];y=b[y]);
                ans++;
                b[x]=y;
                b[a[i].x]=y;
             }
             cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


