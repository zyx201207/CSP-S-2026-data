#include<bits/stdc++.h>
using namespace std;
long long n,m[500001],p[500001][2],t=2,q,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>q;
    for(long long i=1;i<=n;i++){
        cin>>m[i];
    }
    sort(m+1,m+n+1);
    for(long long i=2;i<=n;i++){
        p[t][0]=p[t-1][0]+(t-1)*(m[i]-m[i-1]);
        p[t][1]=i;
        t++;
    }
    for(long long i=1;i<t;i++){
        if(p[i][0]>q){
            cout<<p[i-1][1];
            return 0;
        }
    }
}
