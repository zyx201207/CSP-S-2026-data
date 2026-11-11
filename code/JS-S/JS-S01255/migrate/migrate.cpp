#include<bits/stdc++.h>
#define int long long
#define get() getchar()
#define put(ch) putchar(ch)
using namespace std;
inline int read(){int x=0,f=1;char ch=get();while(ch!=EOF&&(ch<'0'||ch>'9')){if(ch=='-')f=-1;ch=get();}while(ch>='0'&&ch<='9')x=x*10+(ch^'0'),ch=get();return x*f;}
inline void write(int x){if(x<0)put('-'),x=-x;if(x>=10)write(x/10);put((x%10)^'0');}
int a[2000005],nxt[2000005],ss[2000005];
void main1(){
    int n=read(),d=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    int ii=n;
    for(int i=n;i>=1;--i){
        while(a[i]+d<a[ii]){
            --ii;
        }
        nxt[i]=ii;
    }
    if(n<=5000){
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;++j){
                ss[j]=0;
            }
            int mx=nxt[i],num=0;
            ss[i+1]++;
            ss[mx+1]--;
            for(int j=i+1;j<=n;++j){
                if(j>mx){
                    break;
                }
                num+=ss[j];
                ss[mx+1]+=num;
                ss[nxt[j]+1]-=num;
                if(num==2){
                    ++ans;
                }
                if(j==mx){
                    mx=nxt[j];
                }
            }
        }
        write(ans);
    }else{
        int num=a[2]-a[1],len=d/num;
        if(len<=1){
            write(0);
        }else{
            int nm=2*len-1;
            write(n-nm);
        }
    }
    put('\n');
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),t=read();
    while(t--){
        main1();
    }
    return 0;
}
