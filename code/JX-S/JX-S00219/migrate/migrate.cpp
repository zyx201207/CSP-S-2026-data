#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,f[200001][2];
long long a[2000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >>c>>t;
    while(t--){
        cin >>n>>d;
        int as=0;
        for(int i=1;i<=n;i++)
            cin >>a[i];
        for(int l=1;l<=n;l++){
        for(int i=l;i<=n;i++)
            f[i][0]=1e9,f[i][1]=0;
        f[l][0]=0;
        for(int i=l;i<n;i++){
            int m=(upper_bound(a+i+1,a+n+1,a[i]+d)-a)-1;
            //cout <<m<<' ';
            for(int j=i+1;j<=m;j++){
                if(f[j][0]>f[i][0]+1)
                    f[j][0]=f[i][0]+1,f[j][1]=1;
                else if(f[j][0]==f[i][0]+1)
                    f[j][1]++;
                //if(f[j][1]==2)
                    //as++;
                //cout <<j<<' '<<f[j][0]<<endl;
            }
        }
        for(int i=l;i<=n;i++){
            //cout <<f[i][0]<<' '<<f[i][1]<<endl;
            if(f[i][1]==2)
                as++;
        }
        //cout <<endl;
        }
        cout <<as<<"\n";
    }
    return 0;
}
