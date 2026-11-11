#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
int c,T;
int n,L[N],R[N];
int h,t;
int q[N];
ll d,a[N];
vector< pair<int,int> >vec;
vector<int>val;
int getint(){
    char st=getchar();
    int res=0;
    for(;st<'0'||st>'9';st=getchar());
    for(;st>='0'&&st<='9';st=getchar())res=res*10+(st&15);
    return res;
}
ll getll(){
    char st=getchar();
    ll res=0;
    bool t=0;
    for(;st<'0'||st>'9';st=getchar())t|=(st=='-');
    for(;st>='0'&&st<='9';st=getchar())res=res*10+(st&15);
    return t?-res:res;
}
pair<int,int>f[N];
int cnt[N];
void calc_left(int&res,int x,int y){
    int mi=0;
    for(int i=x;i>=y;i--){
        while(h<=t&&q[h]>R[i])cnt[f[q[h]].first]-=f[q[h]].second,h++;
        if(h>t)return;
        while(!cnt[mi])mi++;
        f[i]={mi+1,min(cnt[mi],2)};
        q[++t]=i;
        cnt[f[i].first]+=f[i].second;
        if(f[i].second==1)res++;
    }
    while(h<=t)cnt[f[q[h]].first]-=f[q[h]].second,h++;
}
void calc_right(int&res,int x,int y){
    int mi=0;
    for(int i=x;i<=y;i++){
        while(h<=t&&q[h]<L[i])cnt[f[q[h]].first]-=f[q[h]].second,h++;
        if(h>t)return;
        while(!cnt[mi])mi++;
        f[i]={mi+1,min(cnt[mi],2)};
        q[++t]=i;
        cnt[f[i].first]+=f[i].second;
        if(f[i].second==1)res++;
    }
    while(h<=t)cnt[f[q[h]].first]-=f[q[h]].second,h++;
}
/*void baoli_r(int x,int y,int i,int&res){
    f[i]={0,1};
    q[h=t=1]=i;
    cnt[0]++;
    int mi=0;
    for(int j=i-1;j>=y;j--){
        while(h<=t&&q[h]>R[j])cnt[f[q[h]].first]-=f[q[h]].second,h++;
        if(h>t)return;
        while(!cnt[mi])mi++;
        f[j]={mi+1,min(cnt[mi],3)};
        if(f[j].second==2&&j<=x)res++;
        q[++t]=j;
        cnt[f[j].first]+=f[j].second;
    }
    while(h<=t)cnt[f[q[h]].first]-=f[q[h]].second,h++;
}
void baoli_l(int x,int y,int i,int&res){
    f[i]={0,1};
    q[h=t=1]=i;
    cnt[0]++;
    int mi=0;
    for(int j=i+1;j<=y;j++){
        while(h<=t&&q[h]<L[j])cnt[f[q[h]].first]-=f[q[h]].second,h++;
        if(h>t)return;
        while(!cnt[mi])mi++;
        f[j]={mi+1,min(cnt[mi],3)};
        if(f[j].second==2&&j>=x)res++;
        q[++t]=j;
        cnt[f[j].first]+=f[j].second;
    }
    while(h<=t)cnt[f[q[h]].first]-=f[q[h]].second,h++;
}*/
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=getint(),T=getint();
    while(T--){
        n=getint(),d=getll();
        for(int i=1;i<=n;i++){
            a[i]=getll();
        }
        h=1,t=0;
        for(int i=1;i<=n;i++){
            while(h<=t&&a[q[h]]+d<a[i])h++;
            q[++t]=i;
            L[i]=q[h];
        }
        h=1,t=0;
        for(int i=n;i;i--){
            while(h<=t&&a[q[h]]-d>a[i])h++;
            q[++t]=i;
            R[i]=q[h];
        }
        ll res=0;
        vec.clear();
        val.clear();
        for(int i=2;i+2<=n;i++){
            if(R[L[i+1]]==i+1&&L[R[i]]==i&&L[i+1]!=i&&R[i]!=i+1&&a[i+1]-a[i]<=d){
                vec.emplace_back(L[i+1],R[i]);
                val.emplace_back(i);
            }
        }
        for(int i=0;i<vec.size();i++){
            int x=vec[i].first,y=vec[i].second,l=val[i]-x+1,r=y-val[i],p=val[i],Q=val[i]+1;
            while(a[y]-a[p]<=d||a[R[p]-2]+d>=a[y])p--,l--;
            while(a[Q]-a[x]<=d||a[L[Q]+2]-d<=a[x])Q++,r--;
            if(x>1){
                h=1,t=0;
                for(int j=val[i];j>=x;j--){
                    f[j]={0,1};
                    cnt[0]++;
                    q[++t]=j;
                }
                calc_left(l,x-1,1?1:vec[i-1].first);
            }
            if(y<n){
                h=1,t=0;
                for(int j=val[i]+1;j<=y;j++){
                    f[j]={0,1};
                    cnt[0]++;
                    q[++t]=j;
                }
                calc_right(r,y+1,1?n:vec[i+1].second);
            }
            res=res+1ll*l*r;
        }
        printf("%lld\n",res);
    }
    return 0;
}
