#include<bits/stdc++.h>
using namespace std;
int w[100000];
int k[3];
int a[1000][1000];
int t[1000][1000];
int sz[10000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            sz[a[i][j]]=t[i][j];
        }
    }
    long long cnt=0;
    for(int i=1;i<=q;i++){

            int st,ed;
            cin>>st>>ed;
            cnt+=w[st];
            cnt+=sz[st];
            cnt+=sz[ed];
            cnt+=w[ed];
            cout<<cnt<<endl;

    }



    return 0;
}
