#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long

using namespace std;

const int inf=1e18;

int n;
int K;
int a[2000005];
int f[5005][5005];

static inline bool check(int x,int y){
    return a[x]+K>=a[y];
}

static inline void solve(){
    cin>>n>>K;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    {
        bool ok=true;
        for(int i=1;i<n;++i){
            if(a[i+1]-a[i]!=a[2]-a[1]){
                ok=false;
                break;
            }
        }
        if(ok){
            int ans=0;
            for(int i=1;i<=n;++i){
                int x=(int)(lower_bound(a+1,a+n+1,a[i]-K)-a);
                int d=i-x;
                if(d<=1)
                    continue;
                if(i-d+1-d>=1)
                    ++ans;
            }
            cout<<ans<<'\n';
            return;
        }
    }
    {
        int p=-1;
        for(int i=1;i<=n;++i){
            if(a[1]+K>=a[i]&&a[i]+K>=a[n]){
                p=i;
                break;
            }
        }
        if(p!=-1){
            int ans=0;
            for(int i=p+1;i<=n;++i){
                int x=(int)(lower_bound(a+1,a+n+1,a[i]-K)-a);
                if(x>1){
                    if(x==p){
                        if(i!=p+1){
                            int y=(int)(lower_bound(a+1,a+n+1,a[p+1]-K)-a);
                            if(i!=p+2){
                                int z=(int)(lower_bound(a+1,a+n+1,a[p+2]-K)-a);
                                //y,z-1
                                ans+=z-y;
                            }else{
                                //y,x-1
                                ans+=x-y;
                            }
                        }
                    }else if(x==p-1){
                        if(i!=p+1){
                            int y=(int)(lower_bound(a+1,a+n+1,a[p+1]-K)-a);
                            //1,y-1
                            ans+=y-1;
                        }else{
                            ans+=x-1;
                        }
                    }
                }
            }
            cout<<ans<<'\n';
            return;
        }
    }
    for(int l=1;l<=n;++l)
        for(int r=l+1;r<=n;++r)
            f[l][r]=inf;
    for(int l=1;l<=n;++l){
        int x=l,cnt=0;
        for(int r=l+1;r<=n;++r){
            bool ok=true;
            while(x<r){
                int p=(int)(upper_bound(a+1,a+n+1,a[x]+K)-a-1);
                if(x==p){
                    ok=false;
                    break;
                }
                x=p;
                ++cnt;
            }
            if(!ok)
                break;
            f[l][r]=cnt;
        }
    }
    int ans=0;
    for(int l=1;l<=n;++l){
        for(int r=l+1;r<=n;++r){
            int aim=f[l][r];
            if(aim==inf)
                break;
            int cnt=0;
            int val=1;
            int x=l;
            while(x<r){
                int p=min((int)(upper_bound(a+1,a+n+1,a[x]+K)-a-1),r);
                ++cnt;
                if(p-1>x&&cnt+f[p-1][r]==aim){
                    ++val;
                    if(val>2)
                        break;
                }
                if(p-2>x&&cnt+f[p-2][r]==aim){
                    ++val;
                    if(val>2)
                        break;
                }
                x=p;
            }
            if(val==2)
                ++ans;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _id,T;
    cin>>_id>>T;
    while(T--)
        solve();
    return 0;
}

/*
#include<iostream>

using namespace std;

typedef long long i64;

int n;
i64 K;
i64 a[2000005];

int cnt;
int rt1[2000005];
int rt2[2000005];
struct{
    int ls,rs,val,tag;
}d[100000005];
static inline int clone(int p){
    d[++cnt]=d[p];
    return cnt;
}
static inline void pushtag(int p,int s,int t,int c){
    d[p].val=(t-s+1)*c;
    d[p].tag=c;
}
static inline void pushdown(int p,int s,int t){
    if(d[p].tag==-1)
        return;
    int mid=(s+t)>>1;
    d[p].ls=clone(d[p].ls);
    d[p].rs=clone(d[p].rs);
    pushtag(d[p].ls,s,mid,d[p].tag);
    pushtag(d[p].rs,mid+1,t,d[p].tag);
    d[p].tag=-1;
}
static inline int update(int l,int r,int s,int t,int p){
    p=clone(p);
    if(l<=s&&r>=t){
        pushtag(p,s,t,1);
        return p;
    }
    int mid=(s+t)>>1;
    pushdown(p,s,t);
    if(l<=mid)
        d[p].ls=update(l,r,s,mid,d[p].ls);
    if(r>mid)
        d[p].rs=update(l,r,mid+1,t,d[p].rs);
    d[p].val=d[d[p].ls].val+d[d[p].rs].val;
    return p;
}
static inline int reset(int l,int r,int s,int t,int p){
    p=clone(p);
    if(l<=s&&r>=t){
        pushtag(p,s,t,0);
        return p;
    }
    int mid=(s+t)>>1;
    pushdown(p,s,t);
    if(l<=mid)
        d[p].ls=reset(l,r,s,mid,d[p].ls);
    if(r>mid)
        d[p].rs=reset(l,r,mid+1,t,d[p].rs);
    d[p].val=d[d[p].ls].val+d[d[p].rs].val;
    return p;
}

static inline int get(int x,int s,int t,int p){
    if(s==t)
        return d[p].val;
    int mid=(s+t)>>1;
    pushdown(p,s,t);
    if(x<=mid)
        return get(x,s,mid,d[p].ls);
    return get(x,mid+1,t,d[p].rs);
}
static inline void print(int x){
    cerr<<"  rt1: ";
    for(int i=1;i<=n;++i)
        if(get(i,1,n,rt1[x])==1)
            cerr<<i<<' ';
    cerr<<endl;
    cerr<<"  rt2: ";
    for(int i=1;i<=n;++i)
        if(get(i,1,n,rt2[x])==1)
            cerr<<i<<' ';
    cerr<<endl;
}
static inline void print1(int x){
    for(int i=1;i<=n;++i)
        if(get(i,1,n,rt1[x])==1)
            cerr<<i<<' ';
}

static inline void solve(){
    cin>>n>>K;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    i64 ans=0;
    cnt=0;
    for(int i=1;i<=n;++i){
        int j=(int)(lower_bound(a+1,a+n+1,a[i]-K)-a);
        if(j==i){
            rt1[i]=update(i,i,1,n,0);
            rt2[i]=0;
            continue;
        }
        int z=(int)(lower_bound(a+1,a+n+1,a[j]-K)-a);
        if(z==j){
            cerr<<"C "<<i<<endl;
            rt1[i]=update(j,i,1,n,0);
            rt2[i]=0;
        }else if(j==i-2){
            int x=(int)(lower_bound(a+1,a+n+1,a[j+1]-K)-a);
            if(x==z){
                cerr<<"B "<<i<<endl;
                rt1[i]=update(j,i,1,n,0);
                rt2[i]=clone(rt1[x]);
                if(x+1<j)
                    rt2[i]=update(x+1,j-1,1,n,rt2[i]);
            }else{
                cerr<<"A "<<i<<" j="<<j<<" x="<<x<<endl;
                rt1[i]=clone(rt1[j]);
                rt1[i]=update(j,i,1,n,rt1[i]);
                rt2[i]=clone(rt2[j]);
                if(x<j){
                    rt1[i]=update(x,j-1,1,n,rt1[i]);
                    rt2[i]=reset(x,j-1,1,n,rt2[i]);
                }
            }
        }else if(j<i-2){
            throw 0;
            int x=(int)(lower_bound(a+1,a+n+1,a[j+1]-K)-a);
            int y=(int)(lower_bound(a+1,a+n+1,a[j+2]-K)-a);
            if(y==z){
                rt1[i]=rt2[i]=0;
            }else if(x==z){
                rt1[i]=update(j,i,1,n,0);
                rt2[i]=rt1[z];
                rt2[i]=update(z,y-1,1,n,rt2[i]);
            }else{
                rt1[i]=rt1[z];
                rt1[i]=update(z,x-1,1,n,rt1[i]);
                rt1[i]=update(j,i,1,n,rt1[i]);
                rt2[i]=rt2[z];
                if(x<y)
                    rt2[i]=update(x,y-1,1,n,rt2[i]);
            }
        }else{ // j==i-1
            throw 0;
            rt1[i]=rt1[j];
            rt1[i]=update(i,i,1,n,rt1[i]);
            rt2[i]=rt2[j];
        }
        // cerr<<i<<": "<<d[rt2[i]].val<<endl;
        ans+=d[rt2[i]].val;
        print(i);
        // cerr<<"  ";
        // print1(i);
        // cerr<<endl;
    }
    cout<<ans<<'\n';
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    d[0].tag=-1;
    int _id,T;
    cin>>_id>>T;
    while(T--)
        solve();
    return 0;
}
*/