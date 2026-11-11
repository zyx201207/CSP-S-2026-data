#include<bits/stdc++.h>
using namespace std;
const int N=502;
int a[N][3],t[N][3];
int sub[2*N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m+1);
    int ft=1,fw=1;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][k]>>t[i][k];
        }
    }
    for(int i=1;i<=n;i++){
        sub[a[i][1]]+=t[i][1];
        sub[a[i][2]]+=t[i][2];
    }
    long long sum=0;
    for(int i=1;i<=q;i++){
        int s,e;
        cin>>s>>e;
        sum=w[s]+w[e];
        for(int j=s+1;j<=e-1;j++){
            sum+=sub[j];
        }
        sum=sum+sub[s]/2+sub[e]/2;
        if(s+1==e) sum=w[s]+w[e]+sub[s]/2+sub[e]/2;
    }
    cout<<sum;
    return 0;
}
