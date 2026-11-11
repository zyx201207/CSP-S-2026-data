#include<bits/stdc++.h>
using namespace std;
long long a[100005],c[100005],d[100005];
string b[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("ansout","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    while(n=0){
        n-1;
        ans+=n;
    }
    int vis=0;
    for(int i=1;i<=ans;i++){
        c[i]=a[i];
        for(int j=1;j<=m&&j<=ans;j++){
            c[i]=a[i+j]&&a[i+j+1];
        }
        if(c[i]>vis){
            vis=c[i];
        }
    }
    cout<<vis;
}
