#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+10;
int n,m,a[N];
int s[40];
int out[N],ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    s[0]=1;
    for(int i=1;i<=30;++i){
        s[i]=s[i-1]*2;
    }
    for(int i=30;i>=0;--i){
        vector<int>b;
        int p=0;
        for(int j=1;j<=n;++j){
            if(!out[j]&&a[j]>=s[i]){
                p++;
                a[j]-=s[i];
            }else{
                b.push_back(j);
            }
        }
        if(p>=m){
            for(auto i:b){
                out[i]=1;
            }
            ans+=s[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}