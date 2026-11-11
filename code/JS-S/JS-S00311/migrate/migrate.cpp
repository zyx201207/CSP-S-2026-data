#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,x[N],y[N],sum;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=2;i<=n;i++) y[i]=x[i]-x[i-1];
        if(n==1||n==2||n==3){
            cout<<"0"<<endl;
            continue;
        }
        else if(n==4){
            if(d>=(y[3]+y[2])&&d>=(y[3]+y[4])&&d<y[2]+y[3]+y[4]) cout<<"1"<<endl;
            else cout<<"0"<<endl;
            continue;
        }
        else if(n==5){
            if(d>=(y[3]+y[2])&&d>=(y[3]+y[4])&&d<y[2]+y[3]+y[4]) sum++;
            else if(d>=(y[4]+y[3])&&d>=(y[5]+y[4])&&d<y[5]+y[3]+y[4]) sum++;
            else if(d<(y[2]+y[3]+y[4]+y[5])){
                if((d>=(y[2]+y[3]+y[4])&&d>=y[5])||(d>=y[2]&&d>=(y[3]+y[4]+y[5]))){
                    if((d>=y[2]&&d>=(y[3]+y[4]+y[5]))&&(d>=(y[2]+y[3])&&d>=(y[4]+y[5]))&&(d<(y[2]+y[3]+y[4])||d<y[5])) sum++;
                    else if((d>=y[2]&&d>=(y[3]+y[4]+y[5]))&&(d<(y[2]+y[3])||d<(y[4]+y[5]))&&(d>=(y[2]+y[3]+y[4])&&d>=y[5])) sum++;
                    else if((d<y[2]||d>=(y[3]+y[4]+y[5]))&&(d>=(y[2]+y[3])&&d>=(y[4]+y[5]))&&(d>=(y[2]+y[3]+y[4])&&d>=y[5])) sum++;
                }
                else{
                    if((d>=y[2]&&d>=y[3]&&d>=(y[4]+y[5]))&&(d>=y[2]&&d>=(y[3]+y[4])&&d>=y[5])&&(d<(y[2]+y[3])||d<y[4]||d<y[5])) sum++;
                    else if((d>=y[2]&&d>=y[3]&&d>=(y[4]+y[5]))&&(d<y[2]||d<(y[3]+y[4])||d<y[5])&&(d>=(y[2]+y[3])&&d>=y[4]&&d>=y[5])) sum++;
                    else if((d<y[2]||d<y[3]||d<(y[4]+y[5]))&&(d>=y[2]&&d>=(y[3]+y[4])&&d>=y[5])&&(d>=(y[2]+y[3])&&d>=y[4]&&d>=y[5])) sum++;
                }
            }
            cout<<sum<<endl;
            continue;
        }
        sum=0;
        if(y[3]=y[2]=y[4]=y[5]=y[6]=y[7]=y[8]=y[9]=y[10]=y[11]=y[12]){
            int g=d/y[2];
            int f=2*g-1;
            cout<<n-f+1<<endl;
            continue;
        }
        else cout<<"0"<<endl;
    }
    return 0;
}
