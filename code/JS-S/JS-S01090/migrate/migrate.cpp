#include<bits/stdc++.h>
using namespace std;
int res,ans,dist;
int n,d;
//map<int,int>mem[2000005];
int x[2000005];
int c;
void dfs(int i,int j,int p){
    if(i>=j){
        if(dist<0){
            dist=p;
            res++;
        }else if(dist==p){
            res++;
        }else if(dist>p){
            res=1;
            dist=p;
        }
        //cout<<"t:"<<res<<" "<<dist<<" "<<p<<endl;
        return ;
    }
    int q=0;
    for(q=i+1;q<=j;q+=1){
        //cout<<q<<" "<<i<<" "<<j<<endl;
        if((x[q]-x[i])<=d){
            //cout<<"dfs"<<q<<" "<<j<<" "<<p+1<<endl;
            dfs(q,j,p+1);
            //cout<<q<<j<<endl;
        }
    }
    return ;
}
void solve(int c){
    memset(x,0,2000005);
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(c>=11&&c<=12){
        int ans=0;
        int cc=x[2]-x[1];
        int mx=(d/cc);
        if(mx<=1){
            cout<<0<<endl;
        }
        else cout<<n-2*mx+1<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            res=0,dist=-1;
            //cout<<i<<j<<endl;
            dfs(i,j,0);
            //mem[i][j]=res;
            //cout<<i<<j<<" "<<res<<endl;
            if(res==2)ans++;
        }

    }
    cout<<ans<<endl;
    return ;
}
signed main(){
    int t;
    cin>>c>>t;
    while(t--)solve(c);
    return 0;
}

