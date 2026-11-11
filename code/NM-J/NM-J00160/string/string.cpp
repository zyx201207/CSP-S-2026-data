#include<iostream>
using namespace std;
long long n2=0,n3=1;
char zi[100000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int q;cin>>q;
    while(q--){
        long long n;char m;
        cin>>n>>m;
        n2+=n;
        for(long long i=n3;i<=n2;i++){
            zi[i]=m;
        }
        n3=n2;
    }

    long long  L,R,m=n2/2;
    long long ans=0;
    if(n2%2==1){
        L=m,R=m;
        for(long long i=1;i<=m+1;i++){
            if(zi[L]!=zi[R]) ans++;
            L--;R++;
        }
    }
    else{
        L=m,R=m+1;
        for(long long i=1;i<=m;i++){
            if(zi[L]!=zi[R]) ans++;
            L--;R++;
        }
    }
    cout<<ans;
    return 0;
}

