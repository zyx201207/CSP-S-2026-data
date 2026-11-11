#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int tr[20];
struct tree{
    int f;
    int scnt;
    int s[20];
}a[20];
int test[20];
queue<int>q;
void paint(int idx){
    q.push(idx);
    test[idx]=2;
    while(!q.empty( )){
        int x=q.front( );
        q.pop( );
        test[x]=2;
        if(test[a[x].f]==1){
            test[a[x].f]=2;
            q.push(a[x].f);
        }
        for(auto it:a[x].s){
            if(test[it]==1){
                test[it]=2;
                q.push(it);
            }
        }
    }
    return;
}
int issize( ){
    for(int i=1;i<=n;i++){
        test[i]=tr[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(test[i]==1){
            cnt++;
            paint(i);
        }
    }
    return cnt;
}
queue<pair<int,int>>Q;
int isv[20];
int tlen(int idx){
    while(!Q.empty( )){
        Q.pop( );
    }
    Q.push({idx,0});
    for(int i=1;i<=n;i++){
        isv[i]=0;
    }
    isv[idx]=1;
    while(!Q.empty( )){
        pair<int,int> x=Q.front( );
        Q.pop( );
        int tw=x.first;
        int tv=x.second;
        //cout<<"!!!"<<tw<<' '<<tv<<endl;
        if(test[tw]==2){
            return tv;
        }
        if(isv[a[tw].f]==0){
            isv[a[tw].f]=1;
            Q.push({a[tw].f,tv+1});
        }
        for(auto it:a[tw].s){
            if(isv[it]==0){
                isv[it]=1;
                Q.push({it,tv+1});
            }
        }       
    }
    return -1;
}
int len( ){
    //cout<<"!!!"<<endl;
    int maxn=0;
    for(int i=1;i<=n;i++){
        //cout<<test[i]<<' ';
    }
    //cout<<endl;
    for(int i=1;i<=n;i++){
        if(test[i]!=2){
            maxn=max(maxn,tlen(i));
            //cout<<tlen(i)<<' ';
        }
    }
    //cout<<endl;
    //cout<<"!!!!!"<<maxn<<endl;
    return maxn;
}
int last_ans;
void dfs(int x,int now){
    //cout<<x<<' '<<now<<endl;
    if(x==n+1){
        if(now==m){
            // for(int i=1;i<=n;i++){
            //     cout<<tr[i]<<' ';
            // }
            // cout<<endl;
            if(issize( )<=2){
                last_ans=min(last_ans,len( ));
            }       
            //cout<<"))))))"<<last_ans<<endl;     
            //int jjj;cin>>jjj;
        }

    }else{
        tr[x]=0;
        dfs(x+1,now);
        tr[x]=1;
        dfs(x+1,now+1);
    }
}
void solve( ){
    last_ans=INT_MAX;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        int f,s;
        f=min(x,y);
        s=max(x,y);
        a[s].f=f;
        a[f].scnt++;
        a[f].s[a[f].scnt]=s;
    }
    dfs(1,0);
    cout<<last_ans<<endl;
    return;
}
int main( ){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        solve( );
    }
    return 0;
}
//15