#include<bits/stdc++.h>
using namespace std;
bool s[200005][35];
bool f[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        int t=1;
        while(x>0){
            s[i][t]=x%2;
            x/=2;
            t++;
        }
    }for(int i=1;i<=n;i++) f[i]=1;
    long long sum=0;
    for(int j=30;j>=1;j--){
        int t=0;
        for(int i=1;i<=n;i++){
            if(s[i][j]&&f[i]) t++;
        }if(t>=m){
            sum+=pow(2,j-1);
            for(int i=1;i<=n;i++){
                if(!(s[i][j]&&f[i])) f[i]=0;
            }
        }
    }cout<<sum;
    return 0;
}
