#include<bits/stdc++.h>
using namespace std;
int c,T,n;
long long d;
long long a[2000005];
int s[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    for(int o=1;o<=T;o++){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        int r=1;
        for(int i=1;i<=n;i++){
            while(a[r]<=a[i+1]+d&&r<n) r++;
            s[i]=r;
        }int sum=0;
        for(int i=1;i<=n;i++){
            int d[n+1]={0};
            int t=0;
            for(int j=i;j<=n;j=s[j]){
                t++;
                for(int k=j+1;k<=s[j];k++) d[k]=t;
            }int f[n+1]={0};
            f[i]=1;
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=s[j];k++) if(d[k]==d[j]+1) f[k]+=f[j];
                if(f[j]==2) sum++;
            }
        }cout<<sum<<endl;
    }
    return 0;
}
