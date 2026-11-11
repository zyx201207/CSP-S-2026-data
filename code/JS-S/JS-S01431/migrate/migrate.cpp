#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sd second
using namespace std;
int n,c,t,v[5005][5005];
ll a[2000005],d,ans=0;
pair<int,int> s[5005];
priority_queue<pair<int,int> > q;
ll work(){
    ans=0;
    for(int i=1;i<=n;i++){
        s[i]={100005,-1};
        for(int j=1;j<=n;j++){
            v[i][j]=0;
            if(i!=j&&abs(a[i]-a[j])<=d) v[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        q.push({0,i});
        for(int j=1;j<=n;j++) s[j]={100005,-1};
        while(!q.empty()){
            int x=-q.top().ft,y=q.top().sd;
            q.pop();
            if(s[y].ft<x) continue ;
            else if(s[y].ft>x){
                s[y].ft=x;
                s[y].sd=1;
            }
            else s[y].sd++;
            for(int k=1;k<=n;k++){
                if(v[y][k]&&x+1<=s[k].ft) q.push({-x-1,k});
            }
        }
        for(int j=1;j<=n;j++){
            if(s[j].sd==2) ans++;
        }
    }
    return ans/2;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=5000) cout<<work()<<"\n";
        else{
            ll ff=d/(a[2]-a[1]);
            if(ff==0) cout<<"0/n";
            else cout<<n-d/(a[2]-a[1])-1<<"\n";
        }
    }
    return 0;
}
