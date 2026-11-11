#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,_,x[114514+1919810];
int read(){
    int res=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
    while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
    return res*f;
}
struct node{int val,cnt;};
vector<node>f;
void solve1(){
    int n=read(),d=read(),ans=0;
    for(int i=1;i<=n;++i)x[i]=read();
    for(int i=1;i<=n;++i){
        f.clear();f.push_back((node){0,1});
        for(int j=i+1;j<=n;++j){
            f.push_back((node){114514+1919810,0});
            for(int k=j-1;k>=i&&x[j]-x[k]<=d;--k){
                if(f[k-i].val+1<f[j-i].val)
                    f[j-i]=(node){f[k-i].val+1,f[k-i].cnt};
                else if(f[k-i].val+1==f[j-i].val)
                    f[j-i].cnt+=f[k-i].cnt;
            }
            ans+=f[j-i].cnt==2;
        }
    }
    printf("%lld\n",ans);
}
void solve2(){
    int n=read(),d=read(),ans=0;
    for(int i=1;i<=n;++i)x[i]=read();
    int delta=x[2]-x[1],dis=d/delta*2-1;
    if(dis<2){printf("0\n");return;}
    printf("%lld\n",max(n-dis,0ll));
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();_=read();
    if(c!=11&&c!=12)while(_--)solve1();
    else while(_--)solve2();
}
//g++ -o migrate migrate.cpp -std=c++14 -O2 -static