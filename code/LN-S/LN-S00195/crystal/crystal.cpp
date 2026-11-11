#include <bits/stdc++.h>
using namespace std;
#define int long long
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch=='-'){
        f=-1;ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

const int N=5e5+5;
int n,m;
int a[N], c[N];
int tong[205];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    if(n<=5000){
        int maxn=0;
        for (int i=2;i<n;i++){
            // target -> a[i]
            int tmp=m;
            int cnt=0;
            for(int j=i-1;j>=0;j--){
                if(tmp>=a[i]-a[j]){
                    tmp-=a[i]-a[j];
                    cnt++;
                }
                else break;
            }
            if(cnt>maxn)maxn=cnt;
        }
        printf("%lld\n",maxn+1);
        return 0;
    }
    else if (n>5000){
        bool all_same=1;
        int sm_p=0;
        sm_p=a[2]-a[1];
        for(int i=3;i<=n;i++){
            if(a[i]-a[i-1]!=sm_p){
                all_same=0;
            }
        }
        if(all_same==1){
            if(sm_p==1){
                float ans=sqrt(2*m+0.25)+0.5;
                int anss=floor(ans);
                printf("%lld\n",anss);
                return 0;
            }
            else{
                float ans=sqrt(2*m*1.0/sm_p+0.25)+0.5;
                int anss=floor(ans);
                printf("%lld\n",anss);
                return 0;
            }
        }
        else if(a[n]<=100){  // case 10-12
            for(int i=1;i<=n;i++){
                a[i]+=100;
                tong[a[i]]++;
            }
            int maxn=0;
            for(int i=1;i<=200;i++){
                if(tong[i]==0)continue;
                int tmp=m;
                int cnt=tong[i];
                for(int j=i-1;j>=0;j--){
                    if(tong[j]==0)continue;
                    if(tmp>=(i-j)*tong[j])cnt+=tong[j];
                    else cnt+=tmp/(i-j);
                }
                if(cnt>maxn)maxn=cnt;
            }
            printf("%lld",maxn);
        }
    }
    return 0;
}
