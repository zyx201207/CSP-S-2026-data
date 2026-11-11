#include<bits/stdc++.h>
#define int long long
#define r(x) x=read()
#define w(x) write(x)
#define sp putchar(' ')
#define en putchar('\n')
using namespace std;
int read(){int x=0,f=1;char ch=getchar();while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*f;}
void write(int x){if(x<0) x=-x,putchar('-');if(x>9) write(x/10);putchar(x%10^48);}
const int N=2e5+10;
int a[N];
bool b[N][50];
int n,m;
void print(int x){
    if(x>2) print(x/2);
    w(x%2);
}
vector<int> ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    r(n),r(m);
    for(int i=1;i<=n;i++) {
        r(a[i]);
        //cout<<setw(3)<<a[i]<<':';
        for(int k=0;k<=40;k++){
            b[i][k]=(a[i]>>k)&1;
            //cout<<b[i][k];
        }
        //en;
        ans.push_back(i);
    }
    //en;
    for(int i=40;i>=0;i--){
        int cnt=0;
        for(auto x:ans){
            cnt+=b[x][i];
        }
        if(cnt>=m){
            vector<int> tmp;
            for(auto x:ans){
                if(b[x][i]) tmp.push_back(x);
            }
            ans=tmp;
        }
        //cout<<i<<':';
        //for(auto x:ans){
        //    cout<<x<<' ';
        //}
        //en;
    }
    int res=-1;
    int cnt=0;
    for(auto v:ans){
        if(cnt==0) res=a[v];
        else res&=a[v];
        cnt++;
        //w(v),sp,w(a[v]),en;
        if(cnt==m) break;
    }
    w(res);
    return 0;
}
/*
5 3
31 3 1 15 7
*/
