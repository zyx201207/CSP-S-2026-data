#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define mp make_pair
#define pck putchar(' ')
#define pcn putchar('\n')
#define pb push_back
#define fir first
#define sec second
#define int long long


using namespace std;

int read(){
    int k=1,x=0;
    char ch=gc();
    while(ch!='-' && !isdigit(ch)){
        ch=gc();
    }
    if(ch=='-'){
        k=-1;
        ch=gc();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return k*x;
}

void print(int x){
    if(x<0){
        pc('-');
        x=-x;
    }
    if(x<10){
        pc(x^48);
        return;
    }
    print(x/10);
    pc((x%10)^48);
}

void freop(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
}

int toRmx[2002000],toLmx[2002000];
int a[2000200];
int dp[5050],dis[5050];
int S[5050];
signed main(){
    freop();
    int testid=read(),T=read();
    while(T--){
        int n=read(),d=read();
        for(int i=1;i<=n;i++)a[i]=read();
        int rgt=0;
        for(int i=1;i<=n;i++){
            while(rgt<n && a[rgt+1]-d<=a[i])rgt++,toLmx[rgt]=i;
            toRmx[i]=rgt;
        }
        if(testid<=6){
            int ans=0;
            for(int i=1;i<=n;i++){
                dis[i]=0;
                for(int j=i+1;j<=n;j++){
                    if(toLmx[j]==j)dis[j]=dis[j-1]+1;
                    else dis[j]=dis[max(i,toLmx[j])]+1;
                }
                dp[i]=1;
                for(int j=i+1;j<=n;j++){
                    if(toLmx[j]==j)break;
                    dp[j]=0;
                    for(int k=i;k<j;k++){
                        if(dis[k]==dis[j]-1 && toLmx[j]<=k)dp[j]+=dp[k];
                    }
                    if(dp[j]==2)ans++;
                }
                
            }
            print(ans);
            pcn;
            continue;
        }else if(testid<=10){
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(toLmx[j]+2==toRmx[i])ans++;
                }
            }
            print(ans),pcn;
            continue;
        }
        
        /*if(testid<=10){
            int ans=0;
            for(int i=1;i<=n;i++){
                dis[i]=0;
                for(int j=i+1;j<=n;j++){
                    if(toLmx[j]==j)dis[j]=dis[j-1]+1;
                    else dis[j]=dis[max(i,toLmx[j])]+1;
                }
                S[i]=1;
                S[i-1]=0;
                dp[i]=1;
                int lasdis=0,nowdis=i;
                for(int j=i+1;j<=n;j++){
                    if(dis[j]!=dis[j-1])lasdis=nowdis,nowdis=j;
                    if(toLmx[j]==j)break;
                    else nowdis=j;
                    int R=lasdis,L=toLmx[j];
                    if(L<=R)dp[j]=S[R]-S[L-1];
                    else dp[j]=0;
                    S[j]=S[j-1]+1;
                    if(dp[j]==2)ans++;
                }
            }
            print(ans),pcn;
            continue;
        }*/
        if(testid==11 || testid==12){
            if(a[2]-a[1]>=d)print(0);
            else print(max(n+1-2*d/(a[2]-a[1]),0ll));
            pcn;
            continue;
        }else if(testid==13 || testid==14){
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(toLmx[j]+2==toRmx[i])ans++;
                }
            }
            print(ans),pcn;
            continue;
        }else{
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(toLmx[j]+2==toRmx[i])ans++;
                }
            }
            print(ans),pcn;
            continue;
        }
    }
    return 0;
}
/*
Time 14:30-18:30 don't forget!

luogu:AutumnQ(uid=1038710)
friend:moon_set

chennie,Cubber,absi2011,cmh,aaa_Pigeaon,offoff,Sving1024,placeholder,hyman00,UKB_wyx,TheSky233,LXGOD,rym,SNRJ,moon_set bless me!
The participant who sits next to me says that he is qqiq,is this true?
password:Oct31==Dec25?

rp=inf;

Why Sample #4 32MB?????
16:31 Can I do this? My ideas are wrong, I can't solve it.
*/