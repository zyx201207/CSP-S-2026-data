#include<bits/stdc++.h>
using namespace std;
int m,n,cnt,ans,d;
int a[200005],b[200005];
int x[200005];
void last(int u,int v,int d){
if(v-u!=0;x[u]==1&&x[v]==1)
for(int i=u;i<=v;i++){
    if(b[i]<d){
        cnt++;
        for(int j=1;j<=cnt;j++){
            ans+=2*j;
        }
    }
}

}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>n>>d;
for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i+1]-a[i];
    if(b[i]<=d){
        x[i]=1;
    }
}
last(a[1],a[n],d);
cout<<ans;
}
