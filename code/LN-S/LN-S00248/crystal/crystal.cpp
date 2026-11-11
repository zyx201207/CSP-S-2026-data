#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Q=100005;
LL n,m;
LL a[Q],b[Q];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            b[i]=a[i]-a[i-1];
        }
        else if(a[i]=a[i-1]){
            b[i]=0;
        }
        else if(a[i]<a[i-1]){
            b[i]=a[i-1]-a[i];
        }
    }
    int k=0,t=0;
    for(int i=1;i<=n-1;i++){

        for(int j=i;j>=1;j--){
            if(a[j]==a[j-1]){

                break;
            }
            k=k+b[j];
        }
        if(k>m){
            for(int w=i;w>=1;w--){
                k=k-b[w];
            }
            break;
        }
        t=t+1;
    }
    cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
