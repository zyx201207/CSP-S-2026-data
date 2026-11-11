#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back
#define endl '\n'
using namespace std;
using pii=array<int,2>;
using ll=long long;
const int N=2e6+10;
inline void read(){}
template<class T,class...T2>
inline void read(T&ret,T2&...rest){
    ret=0;char c=gc();bool f=0;
    for(;!isdigit(c)&&c!=EOF;c=gc())f=c=='-';
    for(;isdigit(c);c=gc())ret=ret*10+c-'0';
    if(f)ret=-ret;
    read(rest...);
}
#define cin(...) read(__VA_ARGS__)
template<class T>
inline void print(T x){
    static int stk[40];
    int t=0,f=(x<0);
    if(f)x=-x;
    do stk[t++]=x%10;while(x/=10);
    if(f)pc('-');
    for(;t;pc(stk[--t]+'0'));
}
bool cut[N];
int ID,T,n,nxt[N];
ll d,res,x[N],f[N][2];
int main(){
    freopen("migrate3.in","r",stdin);
    freopen("migrate.out","w",stdout);
    for(cin(ID,T);T;T--){
        cin(n,d),res=0;
        for(int i=1;i<=n;i++)
            cin(x[i]);
        for(int i=n,j=n;i>=1;i--){
            for(;x[j]-x[i]>d;j--);
            nxt[i]=j;
            cut[i]=0;
            if(j==i)
                f[i][0]=0,
                f[i][1]=0;
            else if(j==i+1)
                f[i][0]=f[i+1][0]+1,
                f[i][1]=f[i+1][1],
                cut[i]=1;
            else{
                cut[i+1]=0;
                if(j==i+2){
                    f[i][0]=0;
                    f[i][1]=0;
                    if(nxt[j-1]>j)
                        f[i][1]+=(nxt[j-1]-j);
                    //for(int k=i+3;k<=nxt[j-1];k++)
                    //    f[i][1]+=1;
                    if(cut[nxt[j]]){
                        if(nxt[j-1]<nxt[j])
                            f[i][1]+=f[nxt[j]][1];
                        else
                            f[i][1]+=f[nxt[j]][0];
                    }
                }
                else{
                    f[i][0]=0;
                    f[i][1]=0;
                    if(nxt[j-1]>nxt[j-2])
                        f[i][1]+=(nxt[j-1]-nxt[j-2]);
                    //for(int k=nxt[j-2]+1;k<=nxt[j-1];k++)
                    //    f[i][1]+=1;
                    if(cut[nxt[j]]){
                        if(nxt[j-1]<nxt[j])
                            f[i][1]+=f[nxt[j]][1];
                        else if(nxt[j-2]<nxt[j])
                            f[i][1]+=f[nxt[j]][0];
                    }
                }
            }
            //cerr<<i<<" -> "<<nxt[i]<<"  f:"<<f[i][0]<<" "<<f[i][1]<<endl;
            res+=f[i][1];
        }
        print(res),pc(endl);
        //cerr<<"----------\n";
    }
    return 0;
}
//g++ migrate.cpp -o migrate -std=c++14 -Wall -Wextra -Og -g -Dlocal -fsanitize=address,undefined
//g++ migrate.cpp -o migrate -std=c++14 -O2