#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+10;
int n,m,c[maxn][35],sum[35],res[maxn],ans[35];
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
        int p=0;
        while(a){
            c[i][++p]=a%2;
            a/=2;
            sum[p]+=c[i][p];
        }
    }
    int x=0;
    for(int i=1;i<=35;i++){
        if(sum[i]>=m)x=i;
    }
    int t=1;
    for(int i=x-1;i>=0;i--){
        if(t){
            ans[i+1]=1;
            for(int j=1;j<=n;j++){
                if(c[j][i+1]==0)res[j]=1;
            }
        }
        int s=0;
        for(int j=1;j<=n;j++){
            if(res[j]==0)s+=c[j][i];
        }
        if(s>=m)t=1;
        else t=0;
    }
    ll k=0;
    for(int i=1;i<=35;i++)k+=ans[i]*pow(2,i-1);
    cout<<k;
    return 0;
}
