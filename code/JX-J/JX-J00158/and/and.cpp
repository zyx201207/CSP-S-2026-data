#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],sum=-1e9-10;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=2000){
        if(m==1){
            cout<<a[n];
            return 0;
        }else if(m==2){
            for(int i=1;i<=n;i++){
                for(int l=i+1;l<=n;l++){
                    sum=max(sum,a[i]&a[l]);
                }
            }
            cout<<sum;
            return 0;
        }
    }
    sum=a[n];
    for(int i=n-1,j=1;j<=m-1;i--,j++){
        sum=sum&a[i];
    }
    cout<<sum;
    return 0;
}
