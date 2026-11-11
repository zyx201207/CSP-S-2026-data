#include<bits/stdc++.h>
using namespace std;
#define int long long
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5+5;
int n,a[N];
char c[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    //cerr<<"end\n";
    int cnt=0;
    for(int i=1,j=n;i<=j;i++,j--){
        //cerr<<"i: "<<i<<" j: "<<j<<'\n';
        int t=min(a[i],a[j]);
        if(c[i]!=c[j]){
            cnt+=t;
        }
        a[i]-=t,a[j]-=t;
        if(a[i]){
            i--;
        } else{
            j++;
        }
        //cerr<<"i: "<<i<<" j: "<<j<<'\n';
    }
    cout<<cnt<<'\n';
}

