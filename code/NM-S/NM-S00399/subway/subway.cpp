#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct jh{
    int qd;
    int zd;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int a[m];
    int b[n][2];
    long long u[NULL];
    long long zou[NULL][3];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i][1];
        for(int j=0;j<b[i][1];j++){
            cin>>zou[j][1]>>zou[j][2];
        }
    }
    jh x[q+1];
    int sum[q+1];
    for(int i=0;i<q;i++){
        cin>>x[q].qd>>x[q].zd;
    }
    for(int i=0;i<q;i++){
        for(int i=0;i<n;i++){
            for(int j=0;j<b[i][1];j++){
                sum[i]+=zou[j][2];
            }
        }
        sum[i]+=a[x[q].qd-1]+a[x[q].zd-1];
        cout<<sum[i]<<endl;
    }
    return 0;
}
