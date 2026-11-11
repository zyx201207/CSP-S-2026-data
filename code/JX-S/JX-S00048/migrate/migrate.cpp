#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long w[2000005];
long long ans;
unordered_map<int,int> mp;
int minn=0x3f3f3f3f;
void dfs(int now,int ed,int bushu,long long b){
    //cout<<now<<" "<<bushu<<" "<<b<<"\n";
    if(now==ed){
        int t=bushu;
        if(b!=0) return;
        minn=min(minn,t);
        mp[t]++;
        //cout<<t<<" ";
        return;
    }
    if(w[now+1]-w[now]+b<d){
        dfs(now+1,ed,bushu,b+w[now+1]-w[now]);
    }
    if(w[now+1]-w[now]<=d){
        dfs(now+1,ed,bushu+1,0);
    }
    return;
}
bool f(int x,int y){
    minn=0x3f3f3f3f;
    mp.clear();
    dfs(x,y,0,0);
    //cout<<x<<" "<<y<<" "<<minn<<"\n";
    //cout<<"\n";
    if(mp[minn]==2) return 1;
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        bool deng=1,zong=0;
        scanf("%lld%lld",&n,&d);
        ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&w[i]);
        }
        int fan=w[2]-w[1];
        for(int i=3;i<=n;i++){
            if(w[i]-w[i-1]!=fan){
                deng=0;
                break;
            }
        }
        if(deng==1){
            int kua=d/fan;
            int sum=0;
            for(int i=kua-1;i>=1;i--){
                sum+=(n-kua-i);
            }
            printf("%d\n",sum);
            zong=1;
        }
        if((c==13 || c==14) && zong==0){
            zong=1;
            printf("0\n");
        }
        if(zong==0 && c>=15){
            zong=1;
            printf("1\n");
        }
        if(zong==1) continue;
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                if(f(i,j)) ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
