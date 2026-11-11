#include<bits/stdc++.h>
using namespace std;
const long long N=5e6+10;
long long n,m,a[N],w=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long d=0,u=1,g=1;
    while(u<=g&&g<=n&&n-u+1>w){
        g++;
        d+=(a[g]-a[g-1])*(g-u);
        if(d>m){
            d-=a[g]-a[u];
            u++;
        }else if(d==m){
            if(g-u+1>w){
                w=g-u+1;
            }
        }
    }
    cout<<w<<endl;
    return 0;
}