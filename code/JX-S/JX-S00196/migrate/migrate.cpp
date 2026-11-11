#include<bits/stdc++.h>
using namespace std;
int c,t;long long n,d;long long a[2000006];long long ans=1e18,cnt=0,id=0;
int vis[2000006];
void dfs(int s,int e){
    if(s==e){
        if(ans==d){
            cnt++;
        }
        else if(ans>d){
            ans=d;
            cnt=1;
        }
        return;
    }
    for(int i=s+1;i<=e;i++){
        if(a[i]-a[s]>d)return;
        /*else if(a[e]-a[s]<=d){
            d+=a[e]-a[s];
            dfs(e,e);
            break;
        }*/
        else if(!vis[i]){vis[i]=1;
          d+=a[i]-a[s];
          dfs(i,e);
          vis[i]=0;
          d-=a[i]-a[s];
        }
    }
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
    cin>>n>>d;int id=0;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
id=a[2]-a[1];
if(id>=d||d%id!=0){
        cout<<"0"<<endl;
   }
   else if(n>=4){
    cout<<min((d/id-2),(n-3))<<endl;
}
}

return 0;
}
