#include<bits/stdc++.h>
#define int long long
using namespace std;
bool DEBUG=0;
bool debug=0;
int read(){
    int x=0,f=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar_unlocked();
    }
    while('0'<=c&&c<='9'){
        x=x*10+c-'0';
        c=getchar_unlocked();
    }
    return x*f;
}
constexpr int maxn=2e6+5;

int c,t,n,d;
int a[maxn];
int now[maxn];
int zuo[maxn],tot,rm[maxn],lm[maxn],where[maxn];
vector<int>lis[maxn];
bool vis[maxn];
void qing(){
    memset(vis,0,sizeof vis);
    tot=0;
    memset(now,0,sizeof now);
    memset(rm,0,sizeof rm);
    memset(lm,0,sizeof lm);
    memset(where,0,sizeof where);
    for(int i=1;i<=n;i++)
        lis[i].resize(0,0);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    while(t--){
        n=read();d=read();
        qing();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=2;i<=n;i++){
            if(a[i]-a[i-1]<=d)zuo[i]=i-1;
            else zuo[i]=-1;
        }
        int las_rm=-2;
        for(int i=1;i<=n;i++){
            int pos=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
            // if(DEBUG)cout<<"right_max="<<pos<<endl;
            rm[i]=pos;
            if(rm[i]==las_rm){rm[i]=-1;continue;}
            las_rm=rm[i];
        }
        for(int i=1;i<=n;i++){
            int pos=lower_bound(a+1,a+1+n,a[i]-d)-a;
            // if(DEBUG)cout<<"left_max="<<pos<<endl;
            lm[i]=pos;
        }
        if(debug){
            for(int i=1;i<=n;i++)
                cout<<"rm["<<i<<"]="<<rm[i]<<endl;
        }
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            vis[i]=true;
            tot++;
            lis[tot].push_back(i);
            where[i]=tot;
            now[tot]++;
            int pos=i;
            if(rm[pos]==-1)continue;
            while(rm[pos]<=n){
                if(rm[pos]==pos)break;
                if(rm[pos]==-1)break;
                pos=rm[pos];
                vis[pos]=true;
                if(lm[pos]==lis[tot][now[tot]-1]){
                    lis[tot].push_back(pos);
                    where[pos]=tot;
                    now[tot]++;
                }
            }
        }
        if(DEBUG){
            for(int i=1;i<=tot;i++){
                for(auto v:lis[i])
                    cout<<v<<" ";
                cout<<endl;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int rmm=rm[i];
            if(rmm==-1)continue;
            int z=zuo[rmm];
            if(z==-1)continue;
            int rmmm=rm[z];
            int ww=where[rmmm];
            if(rmmm==-1)continue;
            if(z==i)continue;
            if(rmm==rmmm)continue;
            if(debug){
                cout<<"where[rmmm]="<<where[rmmm]<<endl;
                cout<<"z="<<z<<" rmm="<<rmm<<" rmmm="<<rmmm<<endl;
            }
            int in_pos=upper_bound(lis[ww].begin(),lis[ww].end(),rmmm)-lis[ww].begin();
            if(debug){
                cout<<"a["<<i<<"]="<<a[i]<<"with inpos="<<in_pos<<endl;
                cout<<"size where="<<lis[ww].size()<<endl;
            }
            int ww2=where[i];
            int in2_pos=upper_bound(lis[ww2].begin(),lis[ww2].end(),i)-lis[ww2].begin();
            ans+=(in2_pos)*(lis[ww].size()-in_pos+1);
            // ans+=lis[ww].size()-in_pos+1;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}