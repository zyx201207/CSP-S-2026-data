#include<bits/stdc++.h>
#define i32 signed
#define i64 long long
#define int i64
#define pii pair<int,int>
using namespace std;
const int N=2e6+5;
int c,T;
int n,d;
int a[N];
int c1[N],c2[N],d1[N],d2[N],e2[N];
int b[N];
bool vis[N];
i32 main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>T;
    while(T--){
        if(c==11||c==12){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                c1[i]=c2[i]=d1[i]=d2[i]=b[i]=vis[i]=0;
                cin>>a[i];
            }int ans=0;
            for(int i=1;i<=n;i++){
                int b=lower_bound(a+1,a+1+i,a[i]-d)-a,c=b+1;
                if(b==i)c1[i]=1;
                else if(c==i){
                    c1[i]=1+c1[b];
                    c2[i]=c2[b];
                }else{
                    vis[i]=1;
                    if(vis[c]){
                        c1[i]=i-b+c1[b]-d1[c]+1;
                        d1[i]=i-b;
                        if(b==::b[i-1])d2[i]=c2[i-1],d1[i]=c1[i-1];
                        if(b==::b[c]+1)c2[i]=1;
                        else c2[i]=c2[b]-d2[c]+c1[c]-d1[c+1];
                    }else{
                        c1[i]=i-b+c1[b];
                        d1[i]=i-b;
                        c2[i]=c2[b];
                        if(b==::b[i-1])d2[i]=c2[i-1],d1[i]=c1[i-1];
                    }
                }
                ::b[i]=b;
                ans+=c2[i];
            }
            cout<<ans<<"\n";
        }else{
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                c1[i]=c2[i]=d1[i]=d2[i]=b[i]=vis[i]=0;
                cin>>a[i];
            }int ans=0;
            for(int i=1;i<=n;i++){
                int b=lower_bound(a+1,a+1+i,a[i]-d)-a,c=b+1;
                if(b==i)c1[i]=1;
                else if(c==i){
                    c1[i]=1+c1[b];
                    c2[i]=c2[b];
                }else{
                    vis[i]=1;
                    if(vis[c]){
                        c1[i]=i-b+c1[b]-d1[c]+1;
                        d1[i]=i-b;
                        if(b==::b[i-1])d2[i]=c2[i-1],d1[i]=c1[i-1];
                        c2[i]=c2[b]-d2[c]+c1[c]-d1[c+1];
                    }else{
                        c1[i]=i-b+c1[b];
                        d1[i]=i-b;
                        c2[i]=c2[b];
                        if(b==::b[i-1])d2[i]=c2[i-1],d1[i]=c1[i-1];
                    }
                }
                ::b[i]=b;
                ans+=c2[i];
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
//16：10
/*
0 1
10 3
0 3 6 7 8 9 10 13 16 19

0 1
10 3
0 3 6 7 8 9 10 11 14 17

0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32

0 1
10 21
0 7 14 21 28 35 42 49 56 63

0 1
10 22
0 7 14 21 28 35 42 49 56 63

0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/