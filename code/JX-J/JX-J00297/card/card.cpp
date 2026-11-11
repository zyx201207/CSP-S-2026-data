#include <bits/stdc++.h>
using namespace std;
long long n,m,a[3000005],s[3000005],b[3000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    for(int i = 1;i<=n;i++){
         for(int j = i;j<=n;j++){
            a[j]=b[j];
            for(int k = i;k<j;k++){
                if(a[k]==a[j]){
                    for(int t = k+1;t<=j;t++){
                        a[t]=0;
                    }
                    break;
                }
            }
         }
         for(int m = i;m<=n;m++){
            s[a[m]]++;
         }
    }
    for(int i = 1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
