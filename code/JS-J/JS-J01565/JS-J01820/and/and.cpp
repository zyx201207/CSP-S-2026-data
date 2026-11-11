#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
#define mn "0000000000000000000000000000000000000000"
bool cmp(int a,int b){
    return a>b;
}
int n,m;
int e[45],fng[45],ans[45],_in[N];
string a[N];
string f(int x){
    if(x==0) return "0";
    string ans="";
    while(x!=0){
        ans+=char(x%2+'0');
        x/=2;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    e[0]=1;
    for(int i=1;i<=40;i++) e[i]=e[i-1]*2;
    for(int i=1;i<=n;i++) cin>>_in[i];
    sort(_in+1,_in+n+1,cmp);
    for(int i=1;i<=n;i++){
        a[i]=f(_in[i]);
    }
    int j=40;
    for(int i=1;i<=n;i++){
        while(a[i].size()<j){
            fng[j]=i;
            j--;
        }
    }
    for(int i=j;i>=0;i--) fng[i]=n+1;
    for(int i=31;i>=0;i--){
        int numgood=0;
        for(int j=1;j<fng[i];j++){
            if(a[j][i]=='1') numgood++;
        }
        if(numgood>=m){
            ans[i]=1;
            for(int j=1;j<=n;j++){
                if(a[j][i]!='1') a[j]=mn;
            }
        }
    }
    int res=0;
    for(int i=0;i<=40;i++){
        res+=ans[i]*e[i];
    }
    cout<<res;
    return 0;
}