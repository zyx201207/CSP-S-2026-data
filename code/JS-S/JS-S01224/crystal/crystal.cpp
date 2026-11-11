/*14min AC?*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
inline bool chmax(T &a,const T &b){return a<b?a=b,true:false;}
int n,m,a[500005]={},s=0,ans[500005]={},tans=-1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    sort(a+1,a+n+1);
    if(m+s>=n*a[n]){cout<<n<<endl;}
    s=a[1];
    ans[1]=1;
    int las=1;
    for(int i=2;i<=n;i++){
        while(s+m<(i-las)*a[i]){
            s-=a[las];
            las++;
        }
        ans[i]=i-las+1;
        s+=a[i];
    }
    for(int i=1;i<=n;i++){
        chmax(tans,ans[i]);
    }
    cout<<tans<<endl;
    return 0;
}