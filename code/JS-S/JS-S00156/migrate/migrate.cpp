#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,ma,tt;
long long a[10001];
long long now,num,ans;
void specialA(){
    long long k=ma/tt;
    if(k==1){
        cout<<0<<endl;
        return;
    }
    k=k*2;
    cout<<n-k+1<<endl;
}
void dfs(int x,int y,int d){
    if(d>now)
        return;
    if(x==y){
        if(d==now)
            num++;
        if(d<now)
            now=d,num=1;
        return;
    }
    for(int i=x+1;i<=y;i++){
        if(num>2)
            return;
        if(a[i]-a[x]<=ma)
            dfs(i,y,d+1);
        else
            break;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>ma;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        tt=a[2]-a[1];
        int flag=1;
        for(int i=3;i<=n;i++)
            if(a[i]-a[i-1]!=tt){
                    flag=0;
                break;
            }
        if(flag)
            specialA();
        else{
            for(int i=1;i<=n-3;i++)
                for(int j=i+3;j<=n;j++){
                    now=j-i;
                    num=0;
                    dfs(i,j,0);
                    if(num==2)
                            ans++;
                }
        cout<<ans<<endl;
        }
    }
    return 0;
}
