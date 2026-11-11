#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,n,m,d,p,sum;
    cin>>c>>n>>m>>d>>p;
    int a[100000],b[100000],k,s[m];
    for(int j=1;j<=m;j++){
        cin>>s[m];
    }
    for(int j=1;j<=n;j++){
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>a[i]>>b[i];
        }
    }
    for(int i=1;i<=p;i++){
        int x,y;
        cin>>x>>y;
        sum+=s[x];
        sum+=s[y];
        for(int i=1;i<=k;i++){
            if(x==a[i] && a[i+1]<=y){
                sum+=b[i];
                sum+=b[i+1];
                x=a[i+1];
                continue;
            }
        }
        cout<<sum;
        sum=0;
    }
    return 0;
}
