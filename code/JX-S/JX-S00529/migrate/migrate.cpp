#include<bits/stdc++.h>
using namespace std;
long long c,t,n[100005],d[100005],x[2000005];
int main(){
 ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>n;
    for(int i=0;i<t;i++){
        cin>>n[i]>>d[i];
        for(int j=0;j<n[i];j++){
            cin>>x[i];
        }
    }
    return 0;
}
