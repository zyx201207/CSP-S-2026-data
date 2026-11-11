#include<bits/stdc++.h>
using namespace std;
struct zhan{
    int lu,ti;
};
int c,n,m,d,q,j,a,t,st,en;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int t1[m];
    zhan b[m][n];
    for(int i=0;i<m;i++) cin>>t1[i];
    for(int i=0;i<n;i++){
        cin>>j;
        for(int k=0;k<j;k++){
            cin>>a>>t;
            b[i][a].lu=i;
            b[i][a].ti=t;
        }
    }
    for(int i=0;i<q;i++){
        cin>>st>>en;
    }
    return 0;
}
