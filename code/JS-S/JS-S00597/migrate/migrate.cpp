#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define mk make_pair
using namespace std;
#define int long long
int read()
{
    char c=getchar(); int ret=0,f=1;
    while(c<48||c>57){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
    return ret*f;
}
#define N 2000050
int c,T,n,d,a[N],u,v,b[N];
int f[N],g[N],cl,cr,Ans;
int l,r,_L,_R;

void ch(int n)
{
    //i != i-1
        f[n]=1; 
        for(int i=n-1;i;--i){
            l=a[i-1]; r=a[i];
            u=lower_bound(a+1,a+n+1,l+d+1)-a;
            v=lower_bound(a+1,a+n+1,r+d+1)-a-1;
            // u..v
            if(u>v){
                f[i]=1;
                continue;
            }
            f[i]=1+v-u+f[v];
        }
        //i!=i+1
        g[1]=1; 
        F(i,2,n){
            r=a[i+1]; l=a[i];
            v=lower_bound(a+1,a+n+1,r-d)-a-1;
            u=lower_bound(a+1,a+n+1,l-d)-a;
            // u..v
            if(u>v){
                g[i]=1;
                continue;
            }
            g[i]=1+v-u+g[u];
        }

        //F(i,1,n)cerr<<g[i]<<' ';cerr<<endl;
        //F(i,1,n)cerr<<f[i]<<' ';cerr<<endl;

        F(i,2,n-2){
            //if(a[i+2]-a[i-1]<=d)continue;
            _L = lower_bound(a+1,a+n+1,a[i+2]-d)-a-1; //_L qian
            _R = lower_bound(a+1,a+n+1,a[i-1]+d+1)-a; //_R hou
            _R = max(_R,i+2);
            _L = min(_L,i-1);

            u=lower_bound(a+1,a+n+1,a[i+1]+d+1)-a-1;
            v=lower_bound(a+1,a+n+1,a[i]+d+1)-a-1;
            
            if(v<_R) cr=0;else
            if(u!=v){
                cr = v-_R+1;
            }else{
                cr = v-_R+f[v];
            }

            u=lower_bound(a+1,a+n+1,a[i]-d)-a;
            v=lower_bound(a+1,a+n+1,a[i+1]-d)-a;
            if(v>_L)cl=0;else 
            if(u!=v){
                cl = _L-v+1;
            }else{
                //cerr<<_L<<'*'<<v<<endl;
                cl = _L-v+g[v];
            }
            if(cl>=0 && cr>=0)
            Ans += cl * cr;


            //cerr<<i<<' '<<cl<<' '<<cr<<endl;
        }
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(); T=read();
    while(T--){
        Ans = 0;
        n=read();d=read();
        F(i,1,n)b[i]=read();
        int _ = 1;
        F(i,2,n+1){
            if(i>n || b[i]-b[i-1]>d){
                F(j,_,i-1) a[j-_+1]=b[j]; a[0]=-3.5e18; a[i-_+1]=3.5e18;
                ch(i-_);
                _=i;
            }
        }

        printf("%lld\n",Ans);
    }
}