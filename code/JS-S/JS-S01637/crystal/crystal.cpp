#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long read(){
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long x,n=read(),m=read();
    bool f=1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(i>1&&x!=a[i]-a[i-1])
            f=0;
        x=a[i]-a[i-1];
    }
    sort(a+1,a+n+1);
    if(f){
        long long s=0;
        for(int i=2;i<=n;i++){
            s=s+(a[i]-a[i-1])*(i-1);
            if(s>m){
                cout<<i-1;
                return 0;
            }
        }
    }
    else if(n<10000){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            long long s=0;
            for(int j=i+1;j<=n;j++){
                s=s+(a[j]-a[j-1])*(j-1);
                if(s>m){
                    maxx=max(maxx,(long long)j-i);
                    break;
                }
            }
        }
        cout<<maxx;
    }
    else{
        long long maxx=0,cnt=0;
        for(int i=1;i<=n;i++){
            long long s=0;
            for(int j=i+1;j<=n;j++){
                s=s+(a[j]-a[j-1])*(j-1);
                ++cnt;
                if(s>m){
                    maxx=max(maxx,(long long)j-i);
                    break;
                }
                if(cnt==100000000){
                    cout<<maxx;
                    return 0;
                }
            }
        }
        cout<<maxx;
    }
    return 0;
}
