#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T;
long long a[N];
int main(){
   freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
        cin>>c>>T;
    while(T--){
        long long n,d;
        cin>>n>>d;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long  cha=abs(a[2]-a[1]);
        if(cha>=d||cha==0){
            cout<<0<<endl;

        }else {
            long long  x=d/cha;
            if(x<2||n-2*x+1<0){
                cout<<0<<endl;
            }else{
                cout<<n-2*x+1<<endl;
            }
        }
    }

    return 0;
}

//pian fen lai
//xia ji ba xie de 10 fen
