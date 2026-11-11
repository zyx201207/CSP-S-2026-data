#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d,a[2000005];
uint8_t buf[1<<15],*p,*q;
#define gc() (p==q&&(q=(p=buf)+fread(buf,1,1<<15,stdin)),p==q?EOF:*p++)
long long getint(){
    long long x=0,f=1;
    char ch=gc();
    while(!(ch>='0'&&ch<='9'||ch=='-')) ch=gc();
    if(ch=='-'){
        f=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=gc();
    }
    return x*f;
}
void putint(long long x){
    if(x<10){
        putchar(x+'0');
        return;
    }
    putint(x/10);
    putchar(x%10+'0');
}
namespace subtask1{
    int qu[5005];
    int hd,ed;
    int f[5005];
    int cnt[5005];
    void main(){
        long long ans=0;
        for(int i=1;i<=n;i++){
            hd=ed=1;
            qu[1]=i;
            f[i]=0;
            cnt[i]=1;
            for(int j=i-1;j>=1;j--){
                while(hd<=ed&&a[qu[hd]]-a[j]>d) hd++;
                if(hd<=ed){
                    f[j]=f[qu[hd]]+1;
                    cnt[j]=cnt[qu[hd]];
                }
                else{
                    f[j]=n+1;
                    cnt[j]=0;
                }
                for(int k=hd+1;k<=ed;k++){
                    if(f[qu[k]]==f[qu[hd]]){
                        cnt[j]+=cnt[qu[k]];
                        if(cnt[j]>2) break;
                    }
                    else{
                        break;
                    }
                }
                if(cnt[j]==2){
                    ans++;
                }
                while(hd<=ed&&f[qu[ed]]>f[j]) ed--;
                qu[++ed]=j;
            }
        }
        putint(ans);
        putchar('\n');
    }
}
namespace subtask2{
    void main(){
        d=d/(a[2]-a[1]);
        long long ans=0;
        if(d>1){
            for(int i=d*2;i<=n;i++){
                ans++;
            }
        }
        putint(ans);
        putchar('\n');
    }
}
int main(){
    // double st=clock();
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=getint();
    t=getint();
    // cerr<<c<<" "<<t<<endl;
    while(t--){
        n=getint();
        d=getint();
        for(int i=1;i<=n;i++){
            a[i]=getint();
        }
        // cerr<<(clock()-st)/CLOCKS_PER_SEC<<endl;
        if(c<=10||n<=5000){
            subtask1::main();
        }
        else{
            if(c<=12){
                subtask2::main();
            }
            else{
                puts("0");
            }
        }
        // cerr<<(clock()-st)/CLOCKS_PER_SEC<<endl;
    }
    return 0;
}