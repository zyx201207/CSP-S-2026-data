#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int k,ans;
int x[5050];
void dfs(int nowx,int step,int endw){
    if(nowx==endw){
        if(step<k){
            k=step;
            ans=1;
        }else if(step==k){
            ans++;
        }
        return ;
    }
    for(int i=nowx+1;i<=endw;i++){
        if(x[i]-x[nowx]<=d){
            dfs(i,step+1,endw);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int cnt=0,flg=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                k=INT_MAX;
                ans=0;
                dfs(i,0,j);
                if(ans==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
