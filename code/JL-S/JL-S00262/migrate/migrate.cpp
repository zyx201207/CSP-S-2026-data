#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,a[100000],sum=0;
    int s[100000][100000];
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d;
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[i];
            s[i][0]=0;
            s[0][i]=0;
        }
        for(int k=1;k<=n;k++){
            for(int w=1;w<=d;w++){
                if(s[k][w]==a[i]){
                    s[k][w]++;
                }
                else if(s[k][w]<a[i]){
                    s[k][w]=s[k-1][w]+1;
                }
                else{
                    s[k][w]=s[k-1][w]+s[k-a[i]][w];
                }
                for(int a=1;a<=d;a++){
                    if(s[k][w]==s[k][d]){
                        sum++;
                        break;
                    }
                }
            }
        }
        cout<<sum-1;
        sum=0;
    }
    return 0;
}
