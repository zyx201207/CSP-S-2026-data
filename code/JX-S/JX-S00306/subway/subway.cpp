#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int z[5000][500005];
int a[500005];
int x[500000],y[500000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;

        for(int j=0;j<2*k;j++){
            cin>>z[i][j];
        }
    }
    for(int i=0;i<q;i++){
        cin>>x[i]>>y[i];
    }

    int count=0;
    for(int i=0;i<m;i++){
        count+=a[i];
    }
    cout<<count;
    return 0;
}
