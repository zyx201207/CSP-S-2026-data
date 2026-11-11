#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],ans,minn,a;
void dfs(int i,int j,int y,int cnt){
    if(y>j)return;
    if(y==j){
        if(minn>cnt){
            ans=1;
            minn=cnt;
        }
        else if(minn==cnt){
            ans++;
        }
        return;
    }
    int b=1;
    while((x[y+b]-x[y])<=d&&y+b<=j){
        dfs(i,j,y+b,cnt+1);
        b++;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        a=0;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        for(int i=1;i<=n;i++){
            int b=1;
            for(int j=i;j<=n;j++){
                minn=200005;
                ans=0;

                dfs(i,j,i,2);
                if(ans==2){
                    a++;
                }
            }
        }
        cout<<a<<endl;
    }
    return 0;
}
