#include<bits/stdc++.h>
using namespace std;
int a[2000009];
long long d,n,f=0,ans=INT_MAX;
void dfs(int w,int c,int z){
    if(w==z){
        if(ans>c){
            ans=c;
            f=1;
        }else if(ans==c){
            f++;
        }
        return;
    }
    for(int i=w+1;i<=z;i++){
        int dis=max(a[i]-a[w],a[w]-a[i]);
        if(dis<=d){
            dfs(i,c+1,z);
        }else{
            break;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
            long long s=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                f=1;
                ans=INT_MAX;
                dfs(i,0,j);
                if(f==2) s++;
            }
        }
        cout<<s;
    }
    return 0;
}
