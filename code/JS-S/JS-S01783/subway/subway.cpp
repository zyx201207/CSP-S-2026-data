#include<bits/stdc++.h>
using namespace std;

#define int long long
namespace io{
    int read(){
        int k=0,f=1;
        char c=getchar_unlocked();
        while(c<'0'||c>'9'){
            if(c=='-'){
                f=-1;
            }
            c=getchar_unlocked();
        }
        while(c>='0'&&c<='9'){
            k=k*10+c-'0';
            c=getchar_unlocked();
        }
        return k*f;
    }
    void write(int x){
        if(x<0){
            putchar('-');
            x=-x;
        }
        if(x<10){
            putchar(x+'0');
        }else{
            write(x/10);
            putchar(x%10+'0');
        }
    }
    template<class T>void read(T&x){x=read();}
    template<class First,class... Args>void read(First&first,Args&... arg){read(first);read(arg...);}
    template<class T>void write(T x){write(x);}
    template<class First,class... Args>void write(First first,Args... arg){write(first);write(arg...);}
}
using namespace io;

const int N=510;
const int inf=1e18;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    read(c,n,m,d,q);
    // vector<vector<int>>G1(m+1,vector<int>(n+1,inf));
    // vector<vector<int>>G2(n+1,vector<int>(m+1,inf));
    vector<int>w(m+1);
    vector<vector<int>>dist(m+n+1,vector<int>(m+n+1,inf));
    for(int i=1;i<=m;i++){
        read(w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        read(k);
        for(int j=1;j<=k;j++){
            int a,t;
            read(a,t);
            dist[a][m+i]=dist[m+i][a]=t;
            // G1[a][i]=t;
            // G2[i][a]=t;
        }
    }
    for(int i=1;i<=m+n;i++) dist[i][i]=0;
    for(int k=1;k<=m+n;k++){
        for(int i=1;i<=m+n;i++){
            for(int j=1;j<=m+n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    // for(int i=1;i<=m+n;i++){
    //     for(int j=1;j<=m+n;j++){
    //         cerr<<dist[i][j]<<" ";
    //     }
    //     cerr<<endl;
    // }
    for(int i=1;i<=q;i++){
        int x,y;
        read(x,y);
        write(w[x]+dist[x][y]+w[y]);
        // cerr<<i<<":"<<x<<" "<<y<<endl;
        putchar('\n');
    }
    return 0;
}