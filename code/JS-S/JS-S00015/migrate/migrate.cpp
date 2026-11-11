#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,d,e[2000005],f[2000005],t,sum;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<b;i++){
        cin>>c>>d;
        sum=0;
        t=0;
        for(int j=1;j<=c;j++){
            cin>>e[j];
        }
        f[1]=0;
        for(int j=2;j<=c;j++){
            f[j]=e[j]-e[j-1];
            if(f[j]>d){
                f[j]=-1;
            }
        }
        if(c<2*d){
            cout<<0<<"\n";
            continue;
        }
        for(int j=2*d;j>=1;j--){
            if(f[j]==-1){
                t=j;
                break;
            }
        }
        for(int j=1;j<=c-2*d+1;j++){
            if(f[j+2*d-1]==-1){
                t=j+2*d-1;
                continue;
            }
            if(t>j) continue;
            sum++;
        }
        cout<<sum<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
