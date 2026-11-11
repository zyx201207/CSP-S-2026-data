#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005][35],mlen=-1;
bool f1[200005],f2[35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long num=0;
        while(a[i]){
            num++;
            b[i][num]=a[i]%2;
            a[i]/=2;
        }
        mlen=max(mlen,num);
    }
    for(int i=mlen;i>=1;i--){
        long long cnt=0;
        for(int j=1;j<=n;j++) if(!f1[j]) cnt+=b[j][i];
        if(cnt>=m){
           f2[i]=1;
           for(int j=1;j<=n;j++) if(!b[j][i])f1[j]=1;
        }
    }
    long long cnt=0;
    for(int i=1;i<=mlen;i++) if(f2[i]) cnt+=pow(2,i-1);
    cout<<cnt;
    return 0;
}
