#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
int c,t,n,d;
int cc[N];
int maxx(int a,int b){
    return a>b?a:b;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t-->0){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>cc[i];
        }
        int x;
        for(int i=1;i<=n;i++){
            bool bj=0;
            for(int j=i+1;j<=n;j++){
                if(cc[j]-cc[i]>d){
                    bj=1;
                    break;
                }
            }
            if(bj==0){
                x=i;
                break;
            }
        }
        int l=maxx(0,x-3),r=maxx(0,n-x-2);
        //int L=l;
        //cout<<x<<" "<<l<<" "<<r<<" ";
        if(x>=3&&x!=n)l++;
        if(x<=n-2&&x!=1)l++;
        //cout<<L-l<<endl;
        if(x==1){
            cout<<n-3<<"\n";
        }else{
            cout<<l+r<<"\n";
        }
        
    }
    return 0;
}