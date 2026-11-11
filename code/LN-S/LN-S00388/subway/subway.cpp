#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,aij,tij,w[500010],a[505][500010],r[100010][2];
bool done;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>aij>>tij;
            a[i][aij]=tij;
        }
    }
    for(int i=0;i<q;i++){
        cin>>r[i][0]>>r[i][1];
    }
    int len = INT_MAX;
    for(int I=0;I<q;I++){
        done = 0;
        // Same line
        for(int i=0;i<n;i++){
            // cout<<a[i][r[I][0]]<<' '<<a[i][r[I][1]]<<' '<<w[r[I][0]]<<' '<<w[r[I][1]]<<endl;
            if(a[i][r[I][0]] && a[i][r[I][1]]){
                len = min(len,a[i][r[I][0]]+a[i][r[I][1]]+w[r[I][0]]+w[r[I][1]]);
                done = 1;
                break;
            }
        }
        if(done){
            cout<<len<<endl;
            continue;
        }
        
    }
    return 0;
}