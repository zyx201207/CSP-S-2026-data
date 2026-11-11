#include<bits/stdc++.h>
using namespace std;
#define int long long 
using ii=__int128;
constexpr int maxn=5e5+10;
inline int read(){
    int f=0,num=0,c=cin.rdbuf()->sbumpc();
    while(!isdigit(c)){
        if(c=='-')f=1;
        c=cin.rdbuf()->sbumpc();
    }
    while(isdigit(c)){
        num=(num<<1)+(num<<3)+(c^48);
        c=cin.rdbuf()->sbumpc();
    }
    return f?-num:num;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int c=read(),t=read();
    while(t--){
        int n=read(),d=read();
        vector<int>x(n+1);
        bool dcsl=1,isB=0;
        for(int i=1;i<=n;++i){
            x[i]=read();
        }
        int ans=0;
        if(n==1){
            cout<<"0\n";
            continue;
        }
        int dc=x[2]-x[1];
        for(int i=3;i<=n;++i){
            if(x[i]-x[i-1]!=dc){
                dcsl=0;
                break;
            }
        }
        for(int i=1;i<=n;++i){
            if(x[i]-d<=x[1]&&x[i]+d>=x[n]){
                isB=1;
                break;
            }
        }
        if(dcsl){
            // cerr<<"zzr\n";
            vector<int>f(n+1,1e18);
            vector<int>g(n+1);    
            vector<int>h(n+1);
            unordered_map<int,int>mp;
            {
                int i=1;
                f[i]=0;
                g[i]=1;
                mp[f[i]]=g[i];
                int l=i;
                for(int j=i+1;j<=n;++j){
                    h[j]=h[j-1];
                    while(x[j]-x[l]>d){
                        mp[f[l]]-=g[l];
                        ++l;
                    }
                    if(j==l)break;
                    f[j]=f[l]+1;
                    g[j]=mp[f[l]];
                    mp[f[j]]+=g[j];
                    if(g[j]==2){
                        ++h[j];
                    }
                }
            }
            for(int i=1;i<=n;++i){
                ans+=h[i];
            }
            cout<<ans<<"\n";
            continue;
        }
        
        if((c>=1&&c<=10)||n<=5000){
            for(int i=1;i<=n;++i){
                vector<int>f(n+1,1e18);
                vector<int>g(n+1);
                unordered_map<int,int>mp;
                f[i]=0;
                g[i]=1;
                mp[f[i]]=g[i];
                int l=i;
                for(int j=i+1;j<=n;++j){
                    while(x[j]-x[l]>d){
                        mp[f[l]]-=g[l];
                        ++l;
                    }
                    if(j==l)break;
                    f[j]=f[l]+1;
                    g[j]=mp[f[l]];
                    mp[f[j]]+=g[j];
                    if(g[j]==2){
                        ++ans;
                    }
                }
            }
            cout<<ans<<"\n";
            continue;
        }
        if(isB){
            // cerr<<"zzr\n";
            for(int i=1;i<=n;++i){
                auto getls=[&](int i)->int{
                    int lsd=x[i]-d;
                    int ls=lower_bound(x.begin()+1,x.end(),lsd)-x.begin();
                    return ls;
                };
                int ls=getls(i);
                if(i-ls<=1){
                    continue;
                }
                int u=ls+1,v=ls+2;
                int lu=getls(u),lv=getls(v);
                ans+=max(0ll,lv-lu);
            }
            cout<<ans<<"\n";
            continue;
        }
        
    }
    return 0;
}