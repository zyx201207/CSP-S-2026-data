#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N=1e6+5;
int ans=0;
int n,d;
int a[N];
bool f[N];
int dfs(int x,int y,int cishu,int num){
    if(x==y){
        num++;
        return 0;
    }
    if(cishu<=0){
        return 0;
    }
    if(num>2)return 0;
    else{
        for(int i=x+1;i<=y;i++){
            if(!f[i]&&abs(a[x]-a[i])<=d){
                f[i]=1;
                dfs(i,y,cishu-1,num);
                f[i]=0;
            }
            if(abs(a[x]-a[i])>d)break;
        }
    }
    if(num==2)return 1;
    else return 0;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int k=1;k<=n;k++)f[k]=0;
                f[i]=1;
                int num=dfs(i,j,j-i-2,0);
                ans+=num;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
