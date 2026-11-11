#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,su;
    long long n,d,minn;
    bool flag;
    cin>>c>>t;
    while(t--){
        n=0,d=0,su=0;
        flag=true;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                if(a[j]-a[i]>d){
                    for(int k=i+1;k<=j;k++){
                        if(a[k]-a[k-1]>d) flag=false;
                    }
                   if(flag==false) break;
                   // if((a[j]-a[i])%d==0){
                     //   continue;
                    //}
                    //else minn=(a[j]-a[i])/d+1;
                    if((a[j]-a[i])%d==d-1) su+=1;
                    else continue;
                }
            }
        }
        cout<<su<<endl;
    }
    return 0;
}
