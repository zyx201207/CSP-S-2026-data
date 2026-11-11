/*
g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall
g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall -fsanitize=address

1. pushup & pushdown
2. int overflow? ll space? __int128?
3. guess bravely
4. constant factor VS. log
5. don't be afarid of countings.
6. is the sample large enough?

*/
#include<bits/stdc++.h>
using namespace std;
#define y0 xcxakioi
#define y1 fcyakioi
#define x0 XCXAKIOI
#define x1 FCYAKIOI
namespace File{
    void Redirect(string s){
        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        string Istr=s+".in",Ostr=s+".out";
        freopen(Istr.c_str(),"r",stdin),freopen(Ostr.c_str(),"w",stdout);
    }
}
#define int long long
const int N=2000005,inf=0x3f3f3f3f3f3f3f3fll;
int n,d,a[N],R[N],L[N],tc;
int lft[N],rit[N],lpn[N],rpn[N];
namespace small{
    const int _=5005;
    int ls[_][_],rs[_][_];
    void solve(){
        for(int i=0;i<=n+1;i++){
            memset(ls,0xc0,sizeof(int)*N),memset(rs,0x3f,sizeof(int)*N);
        }
            memset(lft,0,sizeof(int)*(n+2));
    memset(rit,0,sizeof(int)*(n+2));
        for(int i=1;i<=n;i++){
            int las=i,lav=0;
            for(int j=i;j<=n;){
                j=R[j];
                for(int p=las+1;p<=j;p++)rs[i][p]=lav;
                if(las==j)break;
                las=j,lav+=j;
                if(j>=n)break;
            }
            las=i,lav=0;
            for(int j=i;j>=1;){
                j=L[j];
                for(int p=las-1;p>=j;p--)ls[i][p]=lav;
                if(las==j)break;
                las=j,lav+=j;
                if(j<=1)break;
            }
        }
        int ans=0;
        vector<pair<int,int>> vec;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
            if((rs[i][j]-ls[j][i])==1){
                ans++;
 /*               vector<int> lvec,rvec;
                int lp=j,rp=i;
                while(lp>i){
                    lp=L[lp];
                    if(lp>i)lvec.push_back(lp);
                }
                while(rp<j){
                    rp=R[rp];
                    if(rp<j)rvec.push_back(rp);
                }
                reverse(lvec.begin(),lvec.end());
                int ueq=0;
                for(int p=0;p<lvec.size();p++)ueq+=(lvec[p]!=rvec[p]);
//                cout<<ueq<<" "<<i<<' '<<j<<endl;
                assert(ueq==1);*/
            }
/*            if(j<n && rs[i][j]<rs[i][j+1]){
                lft[j]++;
            }
            if(i>1 && ls[i][j]<ls[i-1][j]){
                rit[i]++;
            }*/
//            if(rs[i][j]==ls[j][i])lft[j]++,rit[i]++;
        }
        cout<<ans<<'\n';
        for(int i=0;i<=n+1;i++){
            memset(ls,0xc0,sizeof(int)*N),memset(rs,0x3f,sizeof(int)*N);
        }
    }
}
namespace small2{
    const int _=5005;
    int ls[_][_],rs[_][_];
    void solve(){
        memset(ls,0xc0,sizeof(ls)),memset(rs,0x3f,sizeof(rs));
        for(int i=0;i<=n;i++){
            memset(ls,0xc0,sizeof(int)*(n+1)),memset(rs,0x3f,sizeof(int)*(n+1));
        }
        for(int i=1;i<=n;i++){
            int las=i,lav=0;
            for(int j=i;j<=n;){
                j=R[j];
                for(int p=las+1;p<=j;p++)rs[i][p]=lav;
                if(las==j)break;
                las=j,lav+=j;
                if(j>=n)break;
            }
            las=i,lav=0;
            for(int j=i;j>=1;){
                j=L[j];
                for(int p=las-1;p>=j;p--)ls[i][p]=lav;
                if(las==j)break;
                las=j,lav+=j;
                if(j<=1)break;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
            if(((rs[i][j]-ls[j][i])==1) &&((L[j]==(R[i]-1))))ans+=(lft[i]+1)*(rit[j]+1);
        }
        cout<<ans<<' ';
    }
}
vector<int> LL[N];
int brute=1;
void solve(){
    cin>>n>>d,a[0]=-inf,a[n+1]=inf;
    for(int i=1;i<=n;i++)cin>>a[i],LL[i].clear();
    for(int i=1;i<=n;i++){
        R[i]=R[i-1];
        while(a[R[i]+1]<=a[i]+d)R[i]++;
    }
    L[n+1]=n+1;
    for(int i=n;i;i--){
        L[i]=L[i+1];
        while(a[L[i]-1]>=a[i]-d)L[i]--;
        LL[L[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
//        if(n<=10)cout<<L[i]<<','<<R[i]<<'\n';
        if(L[i]==R[i])continue;
        if(L[i]>=1 && L[i]<=n && R[i]>R[i-1] && R[L[i]]==i)lft[i]=lft[L[i]]+1;
    }
    for(int i=n;i>=1;i--){
        if(L[i]==R[i])continue;
        if(R[i]>=1 && R[i]<=n && L[i]<L[i+1] && L[R[i]]==i)rit[i]=rit[R[i]]+1;
    }
    int ans=0;
if(!brute)if(n<=500)small2::solve();
    
    if(n<=5000){
        small::solve();
if(brute){        memset(L,0,sizeof(int)*(n+2));
    memset(R,0,sizeof(int)*(n+2));
    memset(lft,0,sizeof(int)*(n+2));
    memset(rit,0,sizeof(int)*(n+2));return;}
    }
    
/*    for(int i=1;i<=n;i++){
        if(R[i]>=1 && R[i]<=n)for(int j:LL[R[i]-1])ans+=(lft[i]+1)*(rit[j]+1);
    }*/
 //   for(int j=i+3;j<=n;j++)if(L[j]==R[i]-1)ans+=(lft[i]+1)*(rit[j]+1),cout<<i<<'+'<<j<<' '<<(lft[i]+1)<<'|'<<(rit[j]+1)<<endl,tc-=i*j;
    
    cout<<ans<<'\n';
//    else cout<<"\n";
//    cout<<endl<<endl<<tc<<endl;
    memset(L,0,sizeof(int)*(n+2));
    memset(R,0,sizeof(int)*(n+2));
    memset(lft,0,sizeof(int)*(n+2));
    memset(rit,0,sizeof(int)*(n+2));
}
main(){
    srand(time(0));int T;File::Redirect("migrate");
    cin>>T>>T;while(T--)solve();
}
/*
8 461538461538461535
-1000000000000000000 -846153846153846155 -692307692307692310 -384615384615384620 230769230769230760 538461538461538450 692307692307692295 999999999999999985
*/
/*
14:40 T1
14:45 why is T2 so hard
14:50 it's 800
15:05 T2?
15:10 T2!
15:20 hooray the round is counting-free
BTW why is 3 so hard

n^2 log is 800.
We call a pair primitive when the two paths of it have no insections.
The graph is beautiful and we can do it easily when we have the primitive pairs.
I have simple algorithm of counting the SPs between the paths.

15:35 just check the conclusion.
16:00 It's right?
16:05 It's wrong?
16:06 Only multicase fault.
16:10 how to optimize
the primitive pairs are easy to get and O(n).
16:20 why wrong?????
16:25 
It's not such easy.
build a L-tree and a R-tree
We should count the nodes U, which is an ancestor of I on the R-tree, and U-1 is in the L-subtree of I.
if L[R[u]] is u-1 we call u a fold.
16:30 WTF the "primitive" idea is wrong
16:55 Why wrong?????????
17:10 EVERY NODE ON THE PATH SHOULD BE A PIONEER!!!!!!!
*/